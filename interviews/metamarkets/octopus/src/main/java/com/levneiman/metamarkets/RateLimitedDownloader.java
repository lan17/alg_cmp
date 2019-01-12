package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;
import org.apache.http.HttpEntity;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.config.Registry;
import org.apache.http.config.RegistryBuilder;
import org.apache.http.conn.socket.ConnectionSocketFactory;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.conn.BasicHttpClientConnectionManager;

import java.io.File;
import java.io.FileOutputStream;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;
import java.util.logging.Logger;

public class RateLimitedDownloader implements AutoCloseable, OnBytesRead {
  private static CloseableHttpClient createClient(
      RateLimiter rateLimiter, OnBytesRead onBytesReadListener) {
    Registry<ConnectionSocketFactory> connectionSocketFactoryRegistry =
        RegistryBuilder.<ConnectionSocketFactory>create()
            .register("http", new RateLimitedPlainSocketFactory(rateLimiter, onBytesReadListener))
            .register("https", new RateLimitedSslSocketFactory(rateLimiter, onBytesReadListener))
            .build();

    BasicHttpClientConnectionManager clientConnectionManager =
        new BasicHttpClientConnectionManager(connectionSocketFactoryRegistry);

    CloseableHttpClient httpclient =
        HttpClients.custom().setConnectionManager(clientConnectionManager).build();
    return httpclient;
  }

  private final ExecutorService threadPool;
  private final RateLimiter rateLimiter;
  private final AtomicLong bytesRead;
  private final AtomicInteger bytesReadInLastSecond;
  private final AtomicLong lastTimeWeRolledSecondOver;

  public RateLimitedDownloader(int rateBytes, int numThreads) {
    rateLimiter = RateLimiter.create(rateBytes);
    threadPool = Executors.newFixedThreadPool(numThreads);
    bytesRead = new AtomicLong(0);
    bytesReadInLastSecond = new AtomicInteger(0);
    lastTimeWeRolledSecondOver = new AtomicLong(0);
  }

  /**
   * Download URL to a file.
   *
   * @param url
   * @param outFilePath
   * @return Future with an exception if an error was encountered. Otherwise future will contain a
   *     null.
   */
  public Future<Throwable> downloadToFile(String url, String outFilePath, String ... duplicates) {
    return threadPool.submit(
        () -> {
          HttpGet httpget = new HttpGet(url);

          try (CloseableHttpClient client = createClient(rateLimiter, this)) {
            System.out.println(String.format("\nStarting to download %s to %s", url, outFilePath));
            return client.execute(
                httpget,
                response -> {
                  try {
                    HttpEntity entity = response.getEntity();
                    if (entity != null) {
                      entity.writeTo(new FileOutputStream(new File(outFilePath)));
                      System.out.println(String.format("\nDownloaded %s to %s", url, outFilePath));
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

  /**
   * Record number of bytes we have downloaded.
   *
   * <p>Also update the counter for how many bytes we have downloaded in current second. When we
   * roll over the second, reset the rate counter.
   *
   * @param numBytesRead
   */
  @Override
  public void onBytesRead(int numBytesRead) {
    bytesRead.addAndGet(numBytesRead);
    long currentMs = System.currentTimeMillis();
    if (currentMs - lastTimeWeRolledSecondOver.get() > 1000) {
      System.out.print(
          String.format(
              "Download rate: %d bytes/second. Total bytes downloaded so far: %d\r",
              bytesReadInLastSecond.get(), bytesRead.get()));
      bytesReadInLastSecond.set(0);
      lastTimeWeRolledSecondOver.set(currentMs);
    }
    bytesReadInLastSecond.addAndGet(numBytesRead);
  }

  public long getBytesRead() {
    return bytesRead.get();
  }
}
