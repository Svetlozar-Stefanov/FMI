package bg.sofia.uni.fmi.mjt.filters;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class KeywordFilterTest {
    @Test
    public void testGetKeyword01() {
        RecipeFilterAPI filter = new KeywordFilter("chicken");

        String expected = "&q=chicken";
        String actual = filter.get();

        Assertions.assertEquals(expected, actual,
            "Filter is not converted properly.");
    }

    @Test
    public void testGetKeyword02() {
        RecipeFilterAPI filter = new KeywordFilter("chicken soup");

        String expected = "&q=chicken soup";
        String actual = filter.get();

        Assertions.assertEquals(expected, actual,
            "Filter is not converted properly.");
    }
}
