package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;

import java.io.IOException;
import java.io.InputStream;
import java.net.*;

/**
 * Exactly same as regular Java Socket, except that getInputStream is overloaded to wrap underlying
 * input stream in a {@link RateLimitedInputStream}.
 */
public class RateLimitedSocket extends Socket {
  private RateLimiter rateLimiter;
  private OnBytesRead listener;

  public RateLimitedSocket() {}

  public RateLimitedSocket(Proxy proxy) {
    super(proxy);
  }

  public RateLimitedSocket(SocketImpl impl) throws SocketException {
    super(impl);
  }

  public RateLimitedSocket(String host, int port) throws IOException {
    super(host, port);
  }

  public RateLimitedSocket(InetAddress address, int port) throws IOException {
    super(address, port);
  }

  public RateLimitedSocket(String host, int port, InetAddress localAddr, int localPort)
      throws IOException {
    super(host, port, localAddr, localPort);
  }

  public RateLimitedSocket(InetAddress address, int port, InetAddress localAddr, int localPort)
      throws IOException {
    super(address, port, localAddr, localPort);
  }

  public RateLimitedSocket(String host, int port, boolean stream) throws IOException {
    super(host, port, stream);
  }

  public RateLimitedSocket(InetAddress host, int port, boolean stream) throws IOException {
    super(host, port, stream);
  }

  public void setRateLimiter(RateLimiter rateLimiter) {
    this.rateLimiter = rateLimiter;
  }

  public void setOnBytesReadListener(OnBytesRead listener) {
    this.listener = listener;
  }

  @Override
  public InputStream getInputStream() throws IOException {
    if (rateLimiter != null) {
      return new RateLimitedInputStream(super.getInputStream(), rateLimiter, listener);
    }
    return super.getInputStream();
  }
}
