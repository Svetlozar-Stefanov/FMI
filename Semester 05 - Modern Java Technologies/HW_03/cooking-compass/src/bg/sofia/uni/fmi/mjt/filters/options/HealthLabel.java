package bg.sofia.uni.fmi.mjt.filters.options;

public enum HealthLabel {
    Alcohol_Cocktail,
    Alcohol_Free,
    Celery_Free,
    Crustacean_Free,
    Dairy_Free,
    DASH,
    Egg_Free,
    Fish_Free,
    Fodmap_Free,
    Gluten_Free,
    Immuno_Supportive,
    Keto_Friendly,
    Kidney_Friendly,
    Kosher,
    Low_Fat_Abs,
    Low_Potassium,
    Low_Sugar,
    Lupine_Free,
    Mediterranean,
    Mollusk_Free,
    Mustard_Free,
    No_Oil_Added,
    Paleo,
    Peanut_Free,
    Pescatarian,
    Pork_Free,
    Red_Meat_Free,
    Sesame_Free,
    Shellfish_Free,
    Soy_Free,
    Sugar_Conscious,
    Sulfite_Free,
    Tree_Nut_Free,
    Vegan,
    Vegetarian,
    Wheat_Free;

    public String getQueryableName() {
        if (this.equals(Mediterranean) || this.equals(DASH)) {
            return name();
        }
        return name().toLowerCase().replace('_', '-');
    }
}
