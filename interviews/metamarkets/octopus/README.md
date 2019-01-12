# Octopus

## Compiling
`mvn clean compile assembly:single`
## Running
`java -jar target/octopus.jar -i input.txt -n 8 -l 1m -o out`
## Implementation
I used a few libraries to make my life easier:
- Google Guava for rate limiting:  https://google.github.io/guava/releases/19.0/api/docs/index.html?com/google/common/util/concurrent/RateLimiter.html
- Apache HttpClient: https://hc.apache.org/httpcomponents-client-ga/
- JCommander for parsing CLI options: http://jcommander.org/

Parallel downloads and rate limiting is managed by `RateLimitedDownloader`.

Parallel downloads are implemented by using standard fixed size thread pool.
Rate limiting is done by providing custom socket factories to `HttpClient` which return `RateLimitedSocket`.  `RateLimitedSocket` returns `RateLimitedInputStream`, which throttles underlying `InputStream`.
Throttling is done by re-using same `RateLimiter` across all downloads.  This ensures that we maximize our download speed but not exceed given global limit.

Every time some amount of bytes is downloaded, this fact is reported back to `RateLimitedDownloader` which maintains sum, as well as some logic to display current download rate.  

Trickiest part of this assignment was figuring out how to hook into HttpClient library which I have not used before.  

## Todos

- It seems that limiting is not 100% precise, at least as measured by my hacky rate measuring mechanism.  It is reasonably close however.  I have also used Activity Monitor on my MacOs to test that download speed limit is respected.
- I am probably not using HttpClient quite right, as I create a new instance everytime.  Also there may be SSL/HTTPS issues.  

