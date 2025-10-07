package bg.sofia.uni.fmi.mjt.filters;

import bg.sofia.uni.fmi.mjt.filters.options.HealthLabel;

public class HealthLabelFilter implements RecipeFilterAPI {
    private static final String IDENTIFIER = "&health=";
    HealthLabel[] healthLabels;

    public HealthLabelFilter(HealthLabel... healthLabels) {
        this.healthLabels = healthLabels;
    }

    @Override
    public String get() {
        StringBuilder builder = new StringBuilder();
        for (var healthLabel : healthLabels) {
            builder.append(IDENTIFIER.concat(healthLabel.getQueryableName()));
        }
        return builder.toString();
    }
}
