package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;
import org.apache.http.conn.ssl.SSLConnectionSocketFactory;
import org.apache.http.protocol.HttpContext;
import org.apache.http.ssl.SSLContexts;

import java.io.IOException;
import java.net.Socket;

/**
 * Simply override {@link SSLConnectionSocketFactory} to create a throttled socket. This is very
 * similar to {@link RateLimitedPlainSocketFactory} but we inherit from {@link
 * SSLConnectionSocketFactory} in order to support SSL.
 */
class RateLimitedSslSocketFactory extends SSLConnectionSocketFactory {
  private final RateLimiter rateLimiter;
  private final OnBytesRead onBytesReadListener;

  public RateLimitedSslSocketFactory(RateLimiter rateLimiter, OnBytesRead onBytesReadListener) {
    super(SSLContexts.createDefault(), SSLConnectionSocketFactory.getDefaultHostnameVerifier());
    this.rateLimiter = rateLimiter;
    this.onBytesReadListener = onBytesReadListener;
  }

  @Override
  public Socket createSocket(HttpContext context) throws IOException {
    return new RateLimitedSocket(rateLimiter, onBytesReadListener);
  }
}
