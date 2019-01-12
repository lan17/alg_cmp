package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;
import org.apache.http.conn.ssl.SSLConnectionSocketFactory;
import org.apache.http.protocol.HttpContext;
import org.apache.http.ssl.SSLContexts;

import java.io.IOException;
import java.net.Socket;

/** Simply override {@link SSLConnectionSocketFactory} to create a throttled socket. */
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
    RateLimitedSocket socket = new RateLimitedSocket();
    socket.setRateLimiter(rateLimiter);
    socket.setOnBytesReadListener(onBytesReadListener);
    return socket;
  }
}
