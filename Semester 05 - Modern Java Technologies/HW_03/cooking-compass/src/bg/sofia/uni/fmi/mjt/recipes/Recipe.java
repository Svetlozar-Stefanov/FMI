package bg.sofia.uni.fmi.mjt.recipes;

import java.util.Collection;

public record Recipe(String label, Collection<String> dietLabels, Collection<String> healthLabels,
                     double totalWeight, Collection<String> cuisineType, Collection<String> mealType,
                     Collection<String> dishType, Collection<String> ingredientLines) {
}
