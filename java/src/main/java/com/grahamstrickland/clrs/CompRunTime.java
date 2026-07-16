package com.grahamstrickland.clrs;

import com.grahamstrickland.clrs.algorithms.BigOh;

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

    public static void main(String[] args) {

        System.out.printf("Comparison of running times for the largest problem size n "
                + "of a problem that can be solved in time t, assuming that%n"
                + "the algorithm to solve the problem takes f(n) microseconds:%n"
                + "---------------------------------------------------------------"
                + "-----------------------------------------------------%n"
                + "f(n)\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s\t%12s%n"
                + "---------------------------------------------------------------"
                + "-----------------------------------------------------%n",
                "1 second", "1 minute", "1 hour", "1 day", "1 month", "1 year", "1 century");

        System.out.print("lg(n)");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(Math.pow(2.0, time.toSeconds()) * 1E6);
            System.out.printf("\t%12.0f", smallestN);
        }
        System.out.println();

        System.out.print("sqrt(n)");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(Math.pow(time.toSeconds() * 1E6, 2.0));
            System.out.printf("\t%12.0f", smallestN);
        }
        System.out.println();

        System.out.print("n");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(time.toSeconds() * 1E6);
            System.out.printf("\t%12.0f", smallestN);
        }
        System.out.println();

        System.out.print("nlg(n)");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(BigOh.inverseNLogN(time.toSeconds() * 1E6));
            System.out.printf("\t%12.0f", smallestN);
        }
        System.out.println();

        System.out.print("n^2");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(
                    Math.pow(time.toSeconds() * 1E6, 0.5));
            System.out.printf("\t%12.0f", smallestN);
        }
        System.out.println();

        System.out.print("n^3");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(Math.pow(
                    time.toSeconds() * 1E6, (1.0 / 3.0)));
            System.out.printf("\t%12.0f", smallestN);
        }
        System.out.println();

        System.out.print("2^n");
        for (Duration time : runTimes) {
            double smallestN = Math.floor(
                    ((Math.log(time.toSeconds() * 1E6) /
                            Math.log(2.0))));
            System.out.printf("\t%12.0f", smallestN);
        }
        System.out.println();

        System.out.print("n!");
        for (Duration time : runTimes) {
            double smallestN = BigOh.inverseFactorial(
                    time.toSeconds() * 1E6);
            System.out.printf("\t%12.0f", smallestN);
        }

        System.out.printf("\n-----------------------------------------------------------"
                + "---------------------------------------------------------\n");
    }
}
