package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;
import org.apache.commons.collections4.CollectionUtils;
import org.apache.commons.io.FileUtils;
import org.apache.http.HttpEntity;
import org.apache.http.client.HttpClient;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.config.Registry;
import org.apache.http.config.RegistryBuilder;
import org.apache.http.conn.socket.ConnectionSocketFactory;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.conn.BasicHttpClientConnectionManager;

import java.io.File;
import java.io.FileOutputStream;
import java.util.List;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicLong;

public class RateLimitedDownloader implements AutoCloseable, OnBytesRead {
  /**
   * Construct a new Apache {@link HttpClient} with custom socket factories, which allow us to
   * inject throttling and record number of bytes being read as they are being read.
   *
   * @param rateLimiter
   * @param onBytesReadListener
   * @return
   */
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
  // TODO: output about progress should not be handled by this class.
  private final boolean verbose;

  public RateLimitedDownloader(int rateBytes, int numThreads, boolean verbose) {
    rateLimiter = RateLimiter.create(rateBytes);
    threadPool = Executors.newFixedThreadPool(numThreads);
    this.verbose = verbose;
    bytesRead = new AtomicLong(0);
    bytesReadInLastSecond = new AtomicInteger(0);
    lastTimeWeRolledSecondOver = new AtomicLong(0);
  }

  /**
   * @param url
   * @param outputFiles list of files to save content of url to.
   * @return Future with an exception if an error was encountered. Otherwise future will contain a
   *     null.
   */
  public Future<Throwable> downloadToFile(String url, List<String> outputFiles) {
    if (CollectionUtils.isEmpty(outputFiles)) {
      throw new IllegalArgumentException("No output files specified.");
    }

    return threadPool.submit(
        () -> {
          HttpGet httpget = new HttpGet(url);

          // TODO: There is probably a way to just reuse the client, and its probably more efficient
          // that
          // way.  I didn't have enough time to keep digging into apache library, however.
          try (CloseableHttpClient client = createClient(rateLimiter, this)) {
            if (verbose) {
              System.out.println(String.format("\nStarting to download %s", url));
            }
            return client.execute(
                httpget,
                response -> {
                  try {
                    HttpEntity entity = response.getEntity();
                    if (entity != null) {
                      String outputFile = outputFiles.get(0);
                      entity.writeTo(new FileOutputStream(new File(outputFile)));
                      if (verbose) {
                        System.out.println(String.format("\nDownloaded %s to %s", url, outputFile));
                      }

                      // Just copy downloaded file into the rest of the filenames.
                      File originalFile = new File(outputFile);
                      if (outputFiles.size() > 1) {
                        for (int i = 1; i < outputFiles.size(); i++) {
                          FileUtils.copyFile(originalFile, new File(outputFiles.get(i)));
                        }
                      }
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
      if (verbose) {
        System.out.print(
            String.format(
                "Download rate: %d bytes/second. Total bytes downloaded so far: %d\r",
                bytesReadInLastSecond.get(), bytesRead.get()));
      }
      bytesReadInLastSecond.set(0);
      lastTimeWeRolledSecondOver.set(currentMs);
    }
    bytesReadInLastSecond.addAndGet(numBytesRead);
  }

  public long getBytesRead() {
    return bytesRead.get();
  }
}
