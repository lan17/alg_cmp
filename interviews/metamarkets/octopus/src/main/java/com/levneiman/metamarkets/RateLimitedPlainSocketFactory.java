package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;
import org.apache.http.conn.socket.PlainConnectionSocketFactory;
import org.apache.http.protocol.HttpContext;

import java.io.IOException;
import java.net.Socket;

/**
 * Simply override {@link PlainConnectionSocketFactory#createSocket(HttpContext)} to create a
 * throttled socket.
 */
class RateLimitedPlainSocketFactory extends PlainConnectionSocketFactory {
  private final RateLimiter rateLimiter;
  private final OnBytesRead onBytesReadListener;

  public RateLimitedPlainSocketFactory(RateLimiter rateLimiter, OnBytesRead onBytesReadListener) {
    this.rateLimiter = rateLimiter;
    this.onBytesReadListener = onBytesReadListener;
  }

  @Override
  public Socket createSocket(HttpContext context) throws IOException {
    RateLimitedSocket socket = new RateLimitedSocket();
    socket.setRateLimiter(rateLimiter);
    socket.setOnBytesReadListener(onBytesReadListener);
    return socket;
  }
}
