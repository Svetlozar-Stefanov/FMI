package bg.sofia.uni.fmi.dp.methods.calculators;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;

public class MD5CalculatorTest {
    @Test
    public void testCalculatorNull() {
        Assertions.assertThrows(IllegalArgumentException.class, () -> new MD5Calculator().calculate(null),
                "Null cannot be an argument.");
    }

    @Test
    public void testCalculate01() {
        try (InputStream is = new ByteArrayInputStream("abc".getBytes())) {
            String expected = "900150983cd24fb0d6963f7d28e17f72";
            String actual = new MD5Calculator().calculate(is);
            Assertions.assertEquals(expected, actual,
                "Checksum not calculated properly.");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Test
    public void testCalculate02() {
        try (InputStream is = new ByteArrayInputStream("HelloWorld!".getBytes())) {
            String expected = "06e0e6637d27b2622ab52022db713ce2";
            String actual = new MD5Calculator().calculate(is);
            Assertions.assertEquals(expected, actual,
                "Checksum not calculated properly.");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    @Test
    public void testCalculate03() {
        String testString = """
            And we shouldn’t be here at all, if we’d known more about it before we started. But I suppose it’s often that way. The brave things in the old tales and songs, Mr. Frodo: adventures, as I used to call them. I used to think that they were things the wonderful folk of the stories went out and looked for, because they wanted them, because they were exciting and life was a bit dull, a kind of a sport, as you might say. But that’s not the way, as you put it. But I expect they had lots of chances, like us, of turning back, only they didn’t. And if they had, we shouldn’t know, because they’d have been forgotten. We hear about those as just went on – and not all to a good end, mind you; at least not to what folk inside a story and not outside it call a good end. You know, coming home, and finding things all right, though not quite the same – like old Mr. Bilbo. But those aren’t always the best tales to hear, though they may be the best tales to get landed in! I wonder what sort of a tale we’ve fallen into?""";

        try (InputStream is = new ByteArrayInputStream(testString.getBytes())) {
            String expected = "d74af9bf22ff75e410366919131c110f";
            String actual = new MD5Calculator().calculate(is);
            Assertions.assertEquals(expected, actual,
                "Checksum not calculated properly.");
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
