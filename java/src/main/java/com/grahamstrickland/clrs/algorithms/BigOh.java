/** 
 * Algorithms for Problem p1-1 from p.14 of CLRS 3e.
 */
package com.grahamstrickland.clrs.algorithms;

/**
 * Algorithms used for Big O calculations.
 */
public class BigOh {
    /**
     * Computes the inverse of n log(n).
     *
     * @param x The value x such that n log(n) = x.
     */
    public static double inverseNLogN(double x) {
        int maxIters = 10;
        double a0 = x / log2(x);
        double a1 = 0.0;

        for (int i = 0; i < maxIters; i++) {
            a1 = a0 - ((a0 * log2(a0) - x) / ((1.0 / Math.log(2.0) + log2(a0))));
            if (Math.abs((a1 * log2(a1)) - (a0 * log2(a0))) < 1.0) {
                return a1;
            } else {
                a0 = a1;
            }
        }

        return a1;
    }

    /**
     * Computes the inverse of n!.
     *
     * @param x The value x such that n! = x.
     */
    public static double inverseFactorial(double x) {
        double i = 0;
        double fact = 1;

        while (fact < x) {
            if (i > 0) {
                fact *= i;
            }
            i++;
        }

        return i - 1;
    }

    /**
     * Computes log_2(a).
     *
     * @param a Any double &gt; 0.
     */
    public static double log2(double a) {
        return Math.log(a) / Math.log(2.0);
    }
}
