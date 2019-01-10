package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;

import java.util.concurrent.ExecutorService;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.config.RegistryBuilder;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.impl.conn.BasicHttpClientConnectionManager;

import java.util.concurrent.Executors;
import java.util.concurrent.Future;

public class RateLimitedDownloader {
    private final ExecutorService threadPool;
    private final RateLimiter rateLimiter;

    public RateLimitedDownloader(int rateBytes, int numThreads) {
        rateLimiter = RateLimiter.create(rateBytes);
        threadPool = Executors.newFixedThreadPool(numThreads);
    }

    public Future<byte[]> download(String url) {

        RegistryBuilder.create();
        BasicHttpClientConnectionManager clientConnectionManager = new BasicHttpClientConnectionManager();

        CloseableHttpClient httpclient = HttpClients.custom().setConnectionManager(clientConnectionManager).build();
        HttpGet httpget = new HttpGet("http://httpbin.org/");
        httpget.
        return null;
    }
}
