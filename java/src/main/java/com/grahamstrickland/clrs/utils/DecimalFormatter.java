package com.grahamstrickland.clrs.utils;

import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;

public class DecimalFormatter {
    /** Maximum fraction digits kept in either notation, i.e. six significant figures. */
    private final static int MAX_FRACTION_DIGITS = 5;

    private final static String SCIENTIFIC_PATTERN =
            "0." + "#".repeat(MAX_FRACTION_DIGITS) + "E0";

    private final static String PLAIN_PATTERN = "#." + "#".repeat(MAX_FRACTION_DIGITS);

    /**
     * Format a double to scientific notation when its exponent falls outside [-4, 6),
     * and to plain notation otherwise, keeping at most six significant figures either
     * way. The result is right-aligned in a field of the given width.
     *
     * @param width field width to pad to; the result is longer than this only if six
     *              significant figures cannot fit
     * @throws IllegalArgumentException if width is not positive
     */
    public static String formatDouble(double value, int width) {
        if (width <= 0) {
            throw new IllegalArgumentException("Argument `width` must be a positive value");
        }

        int exponent = (int) Math.floor(Math.log10(Math.abs(value)));
        String pattern = (value != 0 && (exponent < -4 || exponent >= 6))
                ? SCIENTIFIC_PATTERN
                : PLAIN_PATTERN;
        DecimalFormat fmt = new DecimalFormat(pattern, new DecimalFormatSymbols(Locale.US));

        return String.format("%" + width + "s", fmt.format(value));
    }
}
