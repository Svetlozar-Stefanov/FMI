package bg.sofia.uni.fmi.mjt.query_utils;

import bg.sofia.uni.fmi.mjt.exceptions.BadRecipeQueryException;
import bg.sofia.uni.fmi.mjt.exceptions.UnauthorizedQueryException;
import bg.sofia.uni.fmi.mjt.recipes.Recipe;
import com.google.gson.Gson;
import com.google.gson.JsonObject;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpRequest;
import java.net.http.HttpResponse;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

public class RecipeQuerySender {
    private HttpClient client;

    public RecipeQuerySender() {
        client = HttpClient.newHttpClient();
    }

    public RecipeQuerySender(HttpClient client) {
        this.client = client;
    }

    public static RecipeQuerySender newSender() {
        return new RecipeQuerySender();
    }

    public static RecipeQuerySender newSender(HttpClient client) {
        return new RecipeQuerySender(client);
    }

    public Collection<Recipe> send(URI queryUri, int numberOfPages)
        throws BadRecipeQueryException, UnauthorizedQueryException {
        return sendPage(queryUri, numberOfPages, 1, new ArrayList<Recipe>());
    }

    private List<Recipe> sendPage(URI uri, int numberOfPages, int pageNumber, List<Recipe> recipes)
        throws BadRecipeQueryException, UnauthorizedQueryException {
        HttpRequest request = RequestFlyweight.getInstance().getRequest(uri);
        HttpResponse<String> response = null;
        try {
            response = client.send(request, HttpResponse.BodyHandlers.ofString());
        } catch (IOException | InterruptedException e) {
            throw new RuntimeException("An error occurred while sending the request.", e);
        }

        if (response.statusCode() == HttpURLConnection.HTTP_OK) {
            return handleOkQuery(response, numberOfPages, pageNumber, recipes);
        }

        handleBadQuery(response.statusCode());
        return null;
    }

    private List<Recipe> handleOkQuery(HttpResponse<String> response,
                                              int numberOfPages, int pageNumber,
                                              List<Recipe> recipes)
        throws BadRecipeQueryException, UnauthorizedQueryException {
        Gson gson = new Gson();

        JsonObject responseJson = gson.fromJson(response.body(), JsonObject.class);

        var nextPageResponse = responseJson
            .getAsJsonObject("_links")
            .getAsJsonObject("next");
        URI nextPageUri = null;
        if (nextPageResponse != null) {
            nextPageUri = URI.create(nextPageResponse.get("href").getAsString());
        }

        var hits = responseJson.getAsJsonArray("hits");
        if (hits != null) {
            for (var hit : hits) {
                recipes.add(gson.fromJson(hit.getAsJsonObject().get("recipe"), Recipe.class));
            }
        }

        if (pageNumber == numberOfPages || nextPageResponse == null) {
            return recipes;
        }

        return sendPage(nextPageUri, numberOfPages, pageNumber + 1, recipes);
    }

    private void handleBadQuery(int statusCode) throws BadRecipeQueryException, UnauthorizedQueryException {
        switch (statusCode) {
            case HttpURLConnection.HTTP_BAD_REQUEST -> {
                throw new BadRecipeQueryException("Invalid query sent.");
            }
            case HttpURLConnection.HTTP_FORBIDDEN -> {
                throw new UnauthorizedQueryException("Invalid api key or application id.");
            }
            default -> {
                throw new RuntimeException("An unexpected response code was received.");
            }
        }
    }
}
