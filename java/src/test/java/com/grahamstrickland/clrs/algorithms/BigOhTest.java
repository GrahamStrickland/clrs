package com.grahamstrickland.clrs.algorithms;

import static org.junit.jupiter.api.Assertions.assertTrue;

import java.time.Duration;

import org.junit.jupiter.api.Test;

/**
 * Unit tests for Big O algorithms.
 */
public class BigOhTest {
    private final Duration[] runTimes = new Duration[] {
            Duration.ofSeconds(1),
            Duration.ofMinutes(1),
            Duration.ofHours(1),
            Duration.ofDays(1),
            Duration.ofDays(30),
            Duration.ofDays(365),
            Duration.ofDays(36500)
    };
    private final Double tol = 1e-3;

    /**
     * Tests for BigOh.inverseNLogN.
     */
    @Test
    public void inverseNLogNIsCorrect() {
        double[] exps = new double[] {
                62746.0,
                2801417.0,
                133378058.0,
                2755147513.0,
                71870856404.0,
                797633893349.0,
                68654697441062.0
        };

        for (int i = 0; i < runTimes.length; i++) {
            long timeInMicroseconds = runTimes[i].toNanos() / 1000;
            Double res = BigOh.inverseNLogN(timeInMicroseconds);

            assertTrue(Math.abs(res - exps[i]) / exps[i] < tol);
        }
    }

    /**
     * Tests for BigOh.inverseFactorial.
     */
    @Test
    public void inverseFactorialIsCorrect() {
        double[] exps = new double[] { 10.0, 12.0, 13.0, 14.0, 16.0, 17.0, 18.0 };

        for (int i = 0; i < runTimes.length; i++) {
            long timeInMicroseconds = runTimes[i].toNanos() / 1000;
            Double res = BigOh.inverseFactorial(timeInMicroseconds);

            assertTrue(Math.abs(res - exps[i]) / exps[i] < tol);
        }
    }
}
