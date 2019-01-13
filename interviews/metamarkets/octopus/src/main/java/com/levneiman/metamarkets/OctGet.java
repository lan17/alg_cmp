package com.levneiman.metamarkets;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.beust.jcommander.ParameterException;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/** Octopus flavored wget */
public class OctGet {
  private static final Logger LOG = Logger.getLogger(OctGet.class.getName());
  private static Pattern BYTES_PATTERN = Pattern.compile("([0-9]*)(m|k)?");

  /**
   * Convert human representation of amount of bytes into just number of bytes.
   *
   * @param humanBytes a String like 128k or 128m to mean 128 kilobytes or 128 megabytes
   *     respectively. If humanBytes is only a number, its assumed to be bytes.
   * @return
   */
  private static int parseByteString(String humanBytes) {
    Matcher matcher = BYTES_PATTERN.matcher(humanBytes);
    if (!matcher.matches()) {
      throw new IllegalArgumentException(
          "Not in recognized format.  Must begin with a number and end with either k or m, or no suffix.");
    }
    String suffix = matcher.group(2);
    int bytes = Integer.parseInt(matcher.group(1));
    if (suffix != null) {
      if (suffix.equals("k")) {
        bytes *= 1000;
      } else {
        bytes *= 1000 * 1000;
      }
    }

    return bytes;
  }

  public static class OctGetArgs {
    @Parameter(names = "-i", description = "Input File.", required = true)
    public String inputFilePath;

    @Parameter(names = "-o", description = "Output folder.", required = true)
    public String outputFolder;

    @Parameter(names = "-n", description = "Number of limbs to use.", required = true)
    public Integer numberOfThreads;

    @Parameter(names = "-l", description = "Carefulness factor.", required = true)
    public String downloadLimit;

    @Parameter(names = "-v", description = "Verbose mode.  Outputs progress.")
    public boolean verbose = false;
  }

  public static void main(String[] args)
      throws IOException, ExecutionException, InterruptedException {
    // Parse CLI arguments.
    OctGetArgs cliArgs = new OctGetArgs();
    try {
      JCommander.newBuilder().programName("OctGet").addObject(cliArgs).build().parse(args);
    } catch (ParameterException e) {
      System.out.println(e.getMessage());
      e.usage();
      System.exit(1);
    }

    String inputFilePath = cliArgs.inputFilePath;
    String outputFolderPath = cliArgs.outputFolder;
    int bytesLimit = parseByteString(cliArgs.downloadLimit);
    int numThreads = cliArgs.numberOfThreads;

    File outputfolder = new File(outputFolderPath);
    try {
      outputfolder.mkdirs();
    } catch (Exception e) {
      LOG.log(Level.SEVERE, "Couldn't create output folder", e);
      System.exit(1);
    }

    // Parse input file into a map of url to a list of output files.
    Map<String, List<String>> urlToOutputFiles = new HashMap<>();

    try (BufferedReader br = new BufferedReader(new FileReader(new File(inputFilePath)))) {
      String line;
      while ((line = br.readLine()) != null) {
        String[] parts = line.split(" ");
        if (parts.length != 2) {
          LOG.warning("Can't process line: " + line);
          continue;
        }
        String url = parts[0].trim();
        // TODO: Figure out the output paths in cross-platform way.
        String outputFile = outputFolderPath + "/" + parts[1].trim();

        if (!urlToOutputFiles.containsKey(url)) {
          urlToOutputFiles.put(url, new ArrayList<>());
        }
        urlToOutputFiles.get(url).add(outputFile);
      }
    }

    try (RateLimitedDownloader downloader =
        new RateLimitedDownloader(bytesLimit, numThreads, cliArgs.verbose)) {
      long startTimeMs = System.currentTimeMillis();

      Map<String, Future<Throwable>> results = new HashMap<>();

      for (Map.Entry<String, List<String>> task : urlToOutputFiles.entrySet()) {
        String url = task.getKey();
        results.put(url, downloader.downloadToFile(url, task.getValue()));
      }

      for (String url : results.keySet()) {
        // Synchronous join here works because we use ThreadPool in RateLimitedDownloader.  If we
        // didn't then this join approach may result in serializing all downloads in case the work
        // is kicked off when
        // get on future is called and not when we submit task.
        Throwable throwable = results.get(url).get();
        if (throwable != null) {
          LOG.log(Level.WARNING, String.format("Couldn't download %s", url), throwable);
        }
      }
      System.out.println(
          String.format(
              "Running time, seconds: %f", (System.currentTimeMillis() - startTimeMs) / 1000.0));
      System.out.println(String.format("Bytes downloaded: %d", downloader.getBytesRead()));
    }
  }
}
