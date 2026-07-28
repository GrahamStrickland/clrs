package com.grahamstrickland.clrs.utils;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertThrows;

import org.junit.jupiter.api.Test;

/**
 * Unit tests for DecimalFormatter class.
 */
public class DecimalFormatterTest {
    /**
     * Tests for DecimalFormatter.formatDouble.
     */
    @Test
    public void formatsDoublesCorrectly() {
        double[] nums = {
                62746.0,
                2801417.0,
                133378058.0,
                2755147513.0,
                71870856404.0,
                797633893349.0,
                68654697441062.0,
        };
        String[] exps = {
                "       62746",
                "   2.80142E6",
                "   1.33378E8",
                "   2.75515E9",
                "  7.18709E10",
                "  7.97634E11",
                "  6.86547E13",
        };

        for (int i = 0; i < exps.length; i++) {
            assertEquals(exps[i], DecimalFormatter.formatDouble(nums[i], 12),
                    "formatDouble(" + nums[i] + ", 12)");
        }
    }

    /**
     * Negatives must switch to scientific notation at the same magnitude as positives.
     */
    @Test
    public void formatsNegativesSymmetrically() {
        assertEquals("       62746", DecimalFormatter.formatDouble(62746.0, 12));
        assertEquals("      -62746", DecimalFormatter.formatDouble(-62746.0, 12));
        assertEquals("   2.75515E9", DecimalFormatter.formatDouble(2755147513.0, 12));
        assertEquals("  -2.75515E9", DecimalFormatter.formatDouble(-2755147513.0, 12));
    }

    /**
     * Pins the notation switch at an exponent of 6, and the five-fraction-digit cap of
     * plain notation described by {@link DecimalFormatter#formatDouble(double, int)}.
     */
    @Test
    public void formatsBoundaryValuesCorrectly() {
        assertEquals("           0", DecimalFormatter.formatDouble(0.0, 12));
        assertEquals("      999999", DecimalFormatter.formatDouble(999999.0, 12));
        assertEquals("         1E6", DecimalFormatter.formatDouble(1000000.0, 12));
        assertEquals("     0.12346", DecimalFormatter.formatDouble(0.123456789, 12));
        assertEquals("  12345.6789", DecimalFormatter.formatDouble(12345.6789, 12));
    }

    @Test
    public void rejectsNonPositiveWidth() {
        assertThrows(IllegalArgumentException.class,
                () -> DecimalFormatter.formatDouble(1.0, 0));
        assertThrows(IllegalArgumentException.class,
                () -> DecimalFormatter.formatDouble(1.0, -1));
    }
}
