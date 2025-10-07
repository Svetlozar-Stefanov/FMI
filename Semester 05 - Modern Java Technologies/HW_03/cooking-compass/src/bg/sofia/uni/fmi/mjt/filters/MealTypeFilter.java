package bg.sofia.uni.fmi.mjt.filters;

import bg.sofia.uni.fmi.mjt.filters.options.MealType;

public class MealTypeFilter implements RecipeFilterAPI {
    private static final String IDENTIFIER = "&mealType=";
    MealType[] mealTypes;

    public MealTypeFilter(MealType... mealTypes) {
        this.mealTypes = mealTypes;
    }

    @Override
    public String get() {
        StringBuilder builder = new StringBuilder();
        for (var mealType : mealTypes) {
            builder.append(IDENTIFIER.concat(mealType.toString()));
        }
        return builder.toString();
    }
}
