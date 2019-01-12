package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;
import org.apache.http.HttpEntity;
import org.apache.http.HttpHost;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.config.Registry;
import org.apache.http.config.RegistryBuilder;
import org.apache.http.conn.socket.ConnectionSocketFactory;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.conn.BasicHttpClientConnectionManager;
import org.apache.http.protocol.HttpContext;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;

public class RateLimitedDownloader implements AutoCloseable, OnBytesRead {
  private final ExecutorService threadPool;
  private final RateLimiter rateLimiter;
  private final AtomicLong bytesRead;
  private final AtomicInteger bytesReadInLastSecond;
  private final AtomicLong lastTimeRecieved;

  public RateLimitedDownloader(int rateBytes, int numThreads) {
    rateLimiter = RateLimiter.create(rateBytes);
    threadPool = Executors.newFixedThreadPool(numThreads);
    bytesRead = new AtomicLong(0);
    bytesReadInLastSecond = new AtomicInteger(0);
    lastTimeRecieved = new AtomicLong(0);
  }

  private static CloseableHttpClient createClient(
      RateLimiter rateLimiter, OnBytesRead onBytesReadListener) {
    Registry<ConnectionSocketFactory> connectionSocketFactoryRegistry =
        RegistryBuilder.<ConnectionSocketFactory>create()
            .register("http", new RateLimitedSocketFactory(rateLimiter, onBytesReadListener))
            .build();

    BasicHttpClientConnectionManager clientConnectionManager =
        new BasicHttpClientConnectionManager(connectionSocketFactoryRegistry);

    CloseableHttpClient httpclient =
        HttpClients.custom().setConnectionManager(clientConnectionManager).build();
    return httpclient;
  }
  // private final CloseableHttpClient httpClient;

  /**
   * Download URL to a file.
   *
   * @param url
   * @param outFilePath
   * @return Future with an exception if an error was encountered. Otherwise future will contain a
   *     null.
   */
  public Future<Throwable> downloadToFile(String url, String outFilePath) {
    return threadPool.submit(
        () -> {
          HttpGet httpget = new HttpGet(url);

          try (CloseableHttpClient client = createClient(rateLimiter, this)) {
            return client.execute(
                httpget,
                response -> {
                  try {
                    HttpEntity entity = response.getEntity();
                    if (entity != null) {
                      entity.writeTo(new FileOutputStream(new File(outFilePath)));
                    }
                    return null;
                  } catch (Exception e) {
                    return e;
                  }
                });
          } catch (Exception e) {
            return e;
          }
        });
  }

  @Override
  public void close() {
    threadPool.shutdown();
  }

  @Override
  public void onBytesRead(int numBytesRead) {
    bytesRead.addAndGet(numBytesRead);
    long currentMs = System.currentTimeMillis();
    if (currentMs - lastTimeRecieved.get() > 1000) {
      System.out.println(bytesReadInLastSecond.get());
      bytesReadInLastSecond.set(0);
      lastTimeRecieved.set(currentMs);
    }
    bytesReadInLastSecond.addAndGet(numBytesRead);
  }

  public long getBytesRead() {
    return bytesRead.get();
  }

  private static class RateLimitedSocketFactory implements ConnectionSocketFactory {
    private final RateLimiter rateLimiter;
    private final OnBytesRead onBytesReadListener;

    public RateLimitedSocketFactory(RateLimiter rateLimiter, OnBytesRead onBytesReadListener) {
      this.rateLimiter = rateLimiter;
      this.onBytesReadListener = onBytesReadListener;
    }

    public Socket createSocket(HttpContext context) throws IOException {
      RateLimitedSocket socket = new RateLimitedSocket();
      socket.setRateLimiter(rateLimiter);
      socket.setOnBytesReadListener(onBytesReadListener);
      return socket;
    }

    public Socket connectSocket(
        int connectTimeout,
        Socket socket,
        HttpHost host,
        InetSocketAddress remoteAddress,
        InetSocketAddress localAddress,
        HttpContext context)
        throws IOException {
      final Socket sock = socket != null ? socket : createSocket(context);
      if (localAddress != null) {
        sock.bind(localAddress);
      }
      try {
        sock.connect(remoteAddress, connectTimeout);
      } catch (final IOException ex) {
        try {
          sock.close();
        } catch (final IOException ignore) {
        }
        throw ex;
      }
      return sock;
    }
  }
}
