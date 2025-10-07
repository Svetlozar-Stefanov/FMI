package bg.sofia.uni.fmi.mjt.filters;

public class KeywordFilter implements RecipeFilterAPI {
    private static final String IDENTIFIER = "&q=";
    private final String keyword;
    public KeywordFilter(String keyword) {
        this.keyword = keyword;
    }

    @Override
    public String get() {
        return IDENTIFIER.concat(keyword);
    }
}
