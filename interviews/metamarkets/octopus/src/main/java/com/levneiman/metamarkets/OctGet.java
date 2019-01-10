package com.levneiman.metamarkets;

import com.google.common.util.concurrent.RateLimiter;
import org.apache.commons.cli.*;

/**
 * Octopus flavored wget
 */
public class OctGet {
    private static RateLimiter rateLimiter;

    /**
     * Convert human representation of amount of bytes into just number of bytes.
     * @param humanBytes a String like 128k or 128m to mean 128 kilobytes or 128 megabytes respectively.
     * @return
     */
    private static int parseByteString(String humanBytes) {
        return 0;
    }

    public static void main(String [] args) {
        Options options = new Options();
        options.addOption(Option.builder().longOpt("n").required().desc("Number of limbs to use.").build());
        options.addOption(Option.builder().longOpt("l").required().desc("Carefulness factor.").build());
        options.addOption(Option.builder().longOpt("o").required().desc("Output folder.").build());
        options.addOption(Option.builder().longOpt("i").required().desc("Input file.").build());

        CommandLineParser parser = new DefaultParser();
        HelpFormatter formatter = new HelpFormatter();
        CommandLine cmd;

        try {
            cmd = parser.parse(options, args);
        } catch (ParseException e) {
            System.out.println(e.getMessage());
            formatter.printHelp("Careful Octopus", options);

            System.exit(1);
            return;
        }

        String inputFilePath = cmd.getOptionValue("i");
        String outputFilePath = cmd.getOptionValue("o");

        System.out.println(inputFilePath);
        System.out.println(outputFilePath);


    }
}
