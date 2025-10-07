package bg.sofia.uni.fmi.mjt.filters;

import bg.sofia.uni.fmi.mjt.filters.options.HealthLabel;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class HealthLabelFilterTest {
    @Test
    public void testGetSingleLabel() {
        RecipeFilterAPI filter = new HealthLabelFilter(HealthLabel.Alcohol_Free);

        String expected = "&health=alcohol-free";
        String actual = filter.get();

        Assertions.assertEquals(expected, actual,
            "Filter is not converted properly.");
    }

    @Test
    public void testGetMultipleLabels() {
        RecipeFilterAPI filter = new HealthLabelFilter(
            HealthLabel.Alcohol_Free,
            HealthLabel.Gluten_Free,
            HealthLabel.DASH);

        String expected = "&health=alcohol-free&health=gluten-free&health=DASH";
        String actual = filter.get();

        Assertions.assertEquals(expected, actual,
            "Filter is not converted properly.");
    }
}
