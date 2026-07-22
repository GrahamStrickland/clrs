package com.grahamstrickland.clrs;

import com.grahamstrickland.clrs.algorithms.BigOh;
import com.grahamstrickland.clrs.utils.DecimalFormatter;

import java.time.Duration;

/**
 * Program for Problem p1-1 from p.14 of CLRS 3e.
 */
public class CompRunTime {
    private final static Duration[] runTimes = new Duration[] {
            Duration.ofSeconds(1),
            Duration.ofMinutes(1),
            Duration.ofHours(1),
            Duration.ofDays(1),
            Duration.ofDays(30),
            Duration.ofDays(365),
            Duration.ofDays(36500)
    };

    private final static String[] headings = new String[] {
            "1 second", "1 minute", "1 hour", "1 day", "1 month", "1 year", "1 century"
    };

    private final static int LABEL_WIDTH = 8;
    private final static int CELL_WIDTH = 16;

    private final static String LABEL_FMT = "%-" + LABEL_WIDTH + "s";
    private final static String CELL_FMT = "%" + CELL_WIDTH + "s";
    private final static String RULE = "-".repeat(LABEL_WIDTH + CELL_WIDTH * headings.length);

    public static void main(String[] args) {

        System.out.printf("Comparison of running times for the largest problem size n "
                + "of a problem that can be solved in time t, assuming that%n"
                + "the algorithm to solve the problem takes f(n) microseconds:%n"
                + "%s%n", RULE);

        System.out.printf(LABEL_FMT, "f(n)");
        for (String heading : headings) {
            System.out.printf(CELL_FMT, heading);
        }
        System.out.printf("%n%s%n", RULE);

        System.out.printf(LABEL_FMT, "lg(n)");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(Math.pow(2.0, time.toSeconds()) * 1E6);
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf(LABEL_FMT, "sqrt(n)");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(Math.pow(time.toSeconds() * 1E6, 2.0));
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf(LABEL_FMT, "n");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(time.toSeconds() * 1E6);
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf(LABEL_FMT, "nlg(n)");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(BigOh.inverseNLogN(time.toSeconds() * 1E6));
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf(LABEL_FMT, "n^2");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(
                    Math.pow(time.toSeconds() * 1E6, 0.5));
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf(LABEL_FMT, "n^3");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(Math.pow(
                    time.toSeconds() * 1E6, (1.0 / 3.0)));
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf(LABEL_FMT, "2^n");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(
                    ((Math.log(time.toSeconds() * 1E6) /
                            Math.log(2.0))));
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf(LABEL_FMT, "n!");
        for (Duration time : runTimes) {
            double smallestN = BigOh.inverseFactorial(
                    time.toSeconds() * 1E6);
            printCell(smallestN);
        }
        System.out.println();

        System.out.printf("%s%n", RULE);
    }

    private static void printCell(double value) {
        System.out.print(DecimalFormatter.formatDouble(value, CELL_WIDTH));
    }
}
