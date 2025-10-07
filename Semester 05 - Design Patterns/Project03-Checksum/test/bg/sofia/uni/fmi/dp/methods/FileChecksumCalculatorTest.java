package bg.sofia.uni.fmi.dp.methods;

import bg.sofia.uni.fmi.dp.methods.calculators.MD5Calculator;
import bg.sofia.uni.fmi.dp.resources.Constants;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class FileChecksumCalculatorTest {
    @Test
    public void testNullFile() {
        Assertions.assertThrows(IllegalArgumentException.class, () ->
                new FileChecksumCalculator(new MD5Calculator()).calculate(null),
                "File path cannot be null.");
    }

    @Test
    public void testFolderInsteadOfFile() {
        Assertions.assertThrows(IllegalArgumentException.class, () ->
                        new FileChecksumCalculator(new MD5Calculator()).calculate(
                                Constants.TEST_RESOURCE_DIR.resolve("emptyFolder").toAbsolutePath()),
                "File path cannot be null.");
    }

    @Test
    public void testSuccessfulChecksumCalculation() {
        String expected = "02fddaad1bd7474e1521f4002559e7cb";
        String actual = new FileChecksumCalculator(new MD5Calculator()).calculate(
                Constants.TEST_RESOURCE_DIR.resolve("singleFile\\text.txt").toAbsolutePath()
        );

        Assertions.assertEquals(expected, actual,
                "Checksum was not calculated properly.");
    }
}
