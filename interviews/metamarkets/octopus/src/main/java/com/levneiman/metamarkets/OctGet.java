package com.levneiman.metamarkets;

import com.beust.jcommander.JCommander;
import com.beust.jcommander.Parameter;
import com.beust.jcommander.ParameterException;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
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
   *     respectively.
   * @return
   */
  private static int parseByteString(String humanBytes) {
    Matcher matcher = BYTES_PATTERN.matcher(humanBytes);
    if (!matcher.matches()) {
      throw new IllegalArgumentException(
          "Not in recognized format.  Must begin with a number and end with either k or m");
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

  public static void main(String[] args)
      throws IOException, ExecutionException, InterruptedException {
    OctGetArgs jct = new OctGetArgs();
    try {
      JCommander.newBuilder().programName("OctGet").addObject(jct).build().parse(args);
    } catch (ParameterException e) {
      System.out.println(e.getMessage());
      e.usage();
      System.exit(1);
    }

    String inputFilePath = jct.inputFilePath;
    String outputFolderPath = jct.outputFolder;
    int bytesLimit = parseByteString(jct.downloadLimit);
    int numThreads = jct.numberOfThreads;

    File outputfolder = new File(outputFolderPath);
    try {
      outputfolder.mkdirs();
    } catch (Exception e) {
      LOG.log(Level.SEVERE, "Couldn't create output folder", e);
      System.exit(1);
    }

    try (RateLimitedDownloader downloader = new RateLimitedDownloader(bytesLimit, numThreads)) {
      long startTimeMs = System.currentTimeMillis();

      List<Future<Throwable>> results = new ArrayList<>();
      List<String> lines = new ArrayList<>();

      try (BufferedReader br = new BufferedReader(new FileReader(new File(inputFilePath)))) {
        String line;
        while ((line = br.readLine()) != null) {
          lines.add(line);
          String[] parts = line.split(" ");
          results.add(downloader.downloadToFile(parts[0], outputFolderPath + "/" + parts[1]));
        }
      }

      for (int i = 0; i < results.size(); i++) {
        // Synchronous join here works because we use ThreadPool in RateLimitedDownloader.  If we
        // didn't then this join approach may result in serializing all downloads.
        Throwable throwable = results.get(i).get();
        if (throwable != null) {
          LOG.log(Level.WARNING, String.format("Couldn't download %s", lines.get(i)), throwable);
        }
      }
      LOG.info("DONE");
      System.out.println(
          String.format(
              "Running time, seconds: %f", (System.currentTimeMillis() - startTimeMs) / 1000.0));
      System.out.println(String.format("Bytes downloaded: %d", downloader.getBytesRead()));
    }
  }

  public static class OctGetArgs {
    @Parameter(names = "-i", description = "Input File.", required = true)
    public String inputFilePath;

    @Parameter(names = "-o", description = "Output folder.", required = true)
    public String outputFolder;

    @Parameter(names = "-n", description = "Number of limbs to use.", required = true)
    public Integer numberOfThreads;

    @Parameter(names = "-l", description = "Carefulnes factor.", required = true)
    public String downloadLimit;
  }
}
