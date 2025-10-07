package bg.sofia.uni.fmi.mjt.filters;

import bg.sofia.uni.fmi.mjt.filters.options.MealType;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

public class MealTypeFilterTest {
    @Test
    public void testGetSingle() {
        RecipeFilterAPI filter = new MealTypeFilter(MealType.Breakfast);

        String expected = "&mealType=Breakfast";
        String actual = filter.get();

        Assertions.assertEquals(expected, actual,
            "Filter is not converted properly.");
    }

    @Test
    public void testGetMultiple() {
        RecipeFilterAPI filter = new MealTypeFilter(
            MealType.Breakfast,
            MealType.Snack,
            MealType.Dinner);

        String expected = "&mealType=Breakfast&mealType=Snack&mealType=Dinner";
        String actual = filter.get();

        Assertions.assertEquals(expected, actual,
            "Filter is not converted properly.");
    }
}
