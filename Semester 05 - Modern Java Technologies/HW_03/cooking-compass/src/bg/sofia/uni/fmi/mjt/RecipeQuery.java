package bg.sofia.uni.fmi.mjt;

import bg.sofia.uni.fmi.mjt.exceptions.BadRecipeQueryException;
import bg.sofia.uni.fmi.mjt.exceptions.NoFiltersAppliedException;
import bg.sofia.uni.fmi.mjt.exceptions.UnauthorizedQueryException;
import bg.sofia.uni.fmi.mjt.filters.RecipeFilterAPI;
import bg.sofia.uni.fmi.mjt.query_utils.RecipeQuerySender;
import bg.sofia.uni.fmi.mjt.recipes.Recipe;

import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class RecipeQuery {
    private static final String URI_SCHEME = "https";
    private static final String URI_AUTHORITY = "api.edamam.com";
    private static final String URI_ACCESS_POINT = "/api/recipes/v2";
    private static final String URI_SEARCH_SOURCE = "public";
    private static final String API_KEY = "Your API Key here";
    private static final String APPLICATION_ID = "Your App Id here";

    private static final int MAX_NUMBER_OF_PAGES = 3;

    private final String searchSource;
    private final String apiKey;
    private final String applicationId;

    private final List<RecipeFilterAPI> filters;

    public RecipeQuery() {
        this.searchSource = URI_SEARCH_SOURCE;
        this.apiKey = API_KEY;
        this.applicationId = APPLICATION_ID;
        filters = new ArrayList<>();
    }

    public RecipeQuery(String apiKey, String applicationId) {
        this.searchSource = URI_SEARCH_SOURCE;
        this.apiKey = apiKey;
        this.applicationId = applicationId;
        filters = new ArrayList<>();
    }

    public RecipeQuery(String apiKey, String applicationId, String searchSource) {
        this.searchSource = searchSource;
        this.apiKey = apiKey;
        this.applicationId = applicationId;
        filters = new ArrayList<>();
    }

    public static RecipeQuery newQuery() {
        return new RecipeQuery();
    }

    public static RecipeQuery newQuery(String apiKey, String applicationId) {
        return new RecipeQuery(apiKey, applicationId);
    }

    public static RecipeQuery newQuery(String apiKey, String applicationId, String searchSource) {
        return new RecipeQuery(apiKey, applicationId, searchSource);
    }

    public RecipeQuery apply(RecipeFilterAPI... filters) {
        if (filters == null) {
            throw new IllegalArgumentException("Filters cannot be null.");
        }

        for (var filter : filters) {
            if (filter == null) {
                throw new IllegalArgumentException("Filter cannot be null.");
            }
            this.filters.add(filter);
        }
        return this;
    }

    public URI getQueryUri() {
        StringBuilder query = new StringBuilder();
        query.append("type=".concat(searchSource));
        for (var filter : filters) {
            query.append(filter.get());
        }
        query.append("&app_id=".concat(applicationId));
        query.append("&app_key=".concat(apiKey));

        URI queryUri = null;
        try {
            queryUri = new URI(URI_SCHEME, URI_AUTHORITY, URI_ACCESS_POINT, query.toString(), null);
        } catch (URISyntaxException e) {
            throw new RuntimeException("Constructed query is invalid.", e);
        }

        return queryUri;
    }

    public Collection<Recipe> send()
        throws NoFiltersAppliedException, BadRecipeQueryException, UnauthorizedQueryException {
        if (filters.isEmpty()) {
            throw new NoFiltersAppliedException("No filters were applied.");
        }

        URI queryUri = getQueryUri();

        return RecipeQuerySender.newSender().send(queryUri, MAX_NUMBER_OF_PAGES);
    }
}
