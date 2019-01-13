# HTTP Octopus

Kinda like a wget but with more limbs. 

Built using Java 1.8.0_192, Maven 3.6.0, MacOs and IntelliJ.

I estimate the whole thing took me about 3 hours.

## Compiling

`mvn clean compile assembly:single`

## Running

`java -jar target/octopus.jar -i input.txt -n 8 -l 1m -o out`

I have also added extra verbosity flag `-v`.  If specified, download progress will be printed every second or anytime a file is finished downloading.

## Implementation

I used a few libraries to make my life easier:
- Google Guava for rate limiting:  https://google.github.io/guava/releases/19.0/api/docs/index.html?com/google/common/util/concurrent/RateLimiter.html
- Apache HttpClient: https://hc.apache.org/httpcomponents-client-ga/
- Apache commons: https://commons.apache.org/
- JCommander for parsing CLI options: http://jcommander.org/

Parallel downloads and rate limiting is managed by `RateLimitedDownloader`.

Parallel downloads are implemented by using standard fixed size thread pool.
Rate limiting is done by providing custom socket factories to `HttpClient` which return `RateLimitedSocket`.  `RateLimitedSocket` returns `RateLimitedInputStream`, which throttles underlying `InputStream`.
Throttling is done by re-using same `RateLimiter` across all downloads.  This ensures that we maximize our download speed but not exceed given global limit.

Every time some amount of bytes is downloaded, this fact is reported back to `RateLimitedDownloader` which maintains sum, as well as some logic to display current download rate.  

Trickiest part of this assignment was figuring out how to hook into HttpClient library which I have not used before. 
Another tricky thing is minding size of the buffers which are used when whoever reads socket.  If such buffer is larger than the limit, then we need to artificially lower number of bytes read into the larger buffer.


## Todos

- It seems that limiting is not 100% precise, at least as measured by my hacky rate measuring mechanism.  It is reasonably close however.  I have also used Activity Monitor on my MacOs to test that download speed limit is respected.  Algorithm for improving precision of throttling would likely involve playing around with receiving buffer size and rate limiter.  Maybe there is some lower level hints to give to actual OS sockets.
- I am probably not using HttpClient quite right, as I create a new instance everytime.  Also there may be SSL/HTTPS issues.  
- Won't work on windows because I didn't handle paths in cross-platform way.
- Documentation could be better.
- Unit tests.
- Also left some scattered around in code comments.

