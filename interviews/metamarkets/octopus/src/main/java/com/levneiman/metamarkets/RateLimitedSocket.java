package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;

import java.io.IOException;
import java.io.InputStream;
import java.net.Socket;

/**
 * Exactly same as regular Java Socket, except that getInputStream is overloaded to wrap underlying
 * input stream in a {@link RateLimitedInputStream}.
 */
public class RateLimitedSocket extends Socket {
  private RateLimiter rateLimiter;
  private OnBytesRead onBytesReadListener;

  public RateLimitedSocket(RateLimiter rateLimiter, OnBytesRead onBytesReadListener) {
    this.rateLimiter = rateLimiter;
    this.onBytesReadListener = onBytesReadListener;
  }

  @Override
  public InputStream getInputStream() throws IOException {
    if (rateLimiter != null) {
      return new RateLimitedInputStream(super.getInputStream(), rateLimiter, onBytesReadListener);
    }
    return super.getInputStream();
  }
}
