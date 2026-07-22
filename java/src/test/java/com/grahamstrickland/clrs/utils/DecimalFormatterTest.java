package com.grahamstrickland.clrs.utils;

import static org.junit.jupiter.api.Assertions.assertEquals;

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
}
