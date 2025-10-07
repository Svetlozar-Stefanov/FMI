package bg.sofia.uni.fmi.mjt;

import bg.sofia.uni.fmi.mjt.exceptions.NoFiltersAppliedException;
import bg.sofia.uni.fmi.mjt.filters.HealthLabelFilter;
import bg.sofia.uni.fmi.mjt.filters.KeywordFilter;
import bg.sofia.uni.fmi.mjt.filters.MealTypeFilter;
import bg.sofia.uni.fmi.mjt.filters.options.HealthLabel;
import bg.sofia.uni.fmi.mjt.filters.options.MealType;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.net.URI;

public class RecipeQueryTest {
    @Test
    public void testRecipeQueryApplyNull() {
        Assertions.assertThrows(IllegalArgumentException.class,
            () -> RecipeQuery.newQuery().apply(null),
            "Should not accept null as argument.");
    }

    @Test
    public void testRecipeQueryApplyNullFilter() {
        Assertions.assertThrows(IllegalArgumentException.class,
            () -> RecipeQuery.newQuery().apply( new KeywordFilter("test"),
                null, new HealthLabelFilter(HealthLabel.Alcohol_Cocktail)),
            "Should not accept a null filter argument.");
    }

    @Test
    public void testRecipeQuerySingleKeywordFilter() {
        URI expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&q=chicken&app_id=test_id&app_key=test_key");
        URI actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new KeywordFilter("chicken")
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");
    }

    @Test
    public void testRecipeQuerySingleMealTypeFilter() {
        URI expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&mealType=Breakfast&app_id=test_id&app_key=test_key");
        URI actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new MealTypeFilter(MealType.Breakfast)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");
    }

    @Test
    public void testRecipeQueryMultipleMealTypeFilter() {
        URI expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&mealType=Breakfast&mealType=Dinner&app_id=test_id&app_key=test_key");
        URI actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new MealTypeFilter(MealType.Breakfast, MealType.Dinner)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");
    }

    @Test
    public void testRecipeQuerySingleHealthLabelFilter() {
        URI expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&health=alcohol-free&app_id=test_id&app_key=test_key");
        URI actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new HealthLabelFilter(HealthLabel.Alcohol_Free)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");
    }

    @Test
    public void testRecipeQueryMultipleHealthLabelFilter() {
        URI expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&health=alcohol-free&health=gluten-free&app_id=test_id&app_key=test_key");
        URI actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new HealthLabelFilter(HealthLabel.Alcohol_Free, HealthLabel.Gluten_Free)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");
    }

    @Test
    public void testRecipeQueryMultipleFilters() {
        URI expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&q=chicken&health=alcohol-free&app_id=test_id&app_key=test_key");
        URI actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new KeywordFilter("chicken"),
            new HealthLabelFilter(HealthLabel.Alcohol_Free)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");

        expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&q=chicken&mealType=Breakfast&app_id=test_id&app_key=test_key");
        actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new KeywordFilter("chicken"),
            new MealTypeFilter(MealType.Breakfast)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");

        expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&health=alcohol-cocktail&mealType=Breakfast&app_id=test_id&app_key=test_key");
        actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new HealthLabelFilter(HealthLabel.Alcohol_Cocktail),
            new MealTypeFilter(MealType.Breakfast)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");

        expected = URI.create(
            "https://api.edamam.com/api/recipes/v2?type=public&q=chicken&health=alcohol-cocktail&mealType=Breakfast&app_id=test_id&app_key=test_key");
        actual = RecipeQuery.newQuery("test_key", "test_id").apply(
            new KeywordFilter("chicken"),
            new HealthLabelFilter(HealthLabel.Alcohol_Cocktail),
            new MealTypeFilter(MealType.Breakfast)
        ).getQueryUri();

        Assertions.assertEquals(expected, actual,
            "Request uri was not properly constructed.");
    }

    @Test
    public void testSendNoFilter() {
        Assertions.assertThrows(NoFiltersAppliedException.class, () ->
                RecipeQuery.newQuery().send(),
            "Cannot sent a request without at least one filter.");
    }
}