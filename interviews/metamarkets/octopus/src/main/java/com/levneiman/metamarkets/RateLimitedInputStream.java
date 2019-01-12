package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;

import java.io.IOException;
import java.io.InputStream;

/**
 * Wrap a given input stream and read from it after acquiring specified {@link RateLimiter}.
 *
 * <p>This throttles consumer of the input stream according to whatever limit {@link RateLimiter}
 * has.
 */
public class RateLimitedInputStream extends InputStream {
  private final InputStream underlyingStream;
  private final RateLimiter rateLimiter;
  private final OnBytesRead onBytesReadListener;

  public RateLimitedInputStream(
      InputStream underlyingStream, RateLimiter rateLimiter, OnBytesRead onBytesReadListener) {
    this.underlyingStream = underlyingStream;
    this.rateLimiter = rateLimiter;
    this.onBytesReadListener = onBytesReadListener;
  }

  public int read() throws IOException {
    rateLimiter.acquire(1);
    int ret = underlyingStream.read();
    onBytesReadListener.onBytesRead(1);
    return ret;
  }

  @Override
  public int read(byte[] b, int off, int len) throws IOException {
    // If buffer we are trying to read to is larger than rate, we need to artificially lower number
    // of bytes to read at once.
    if (len > rateLimiter.getRate()) {
      len = (int)rateLimiter.getRate()/200;
    }

    rateLimiter.acquire(len);
    int ret = underlyingStream.read(b, off, len);
    onBytesReadListener.onBytesRead(ret);
    return ret;
  }
}
