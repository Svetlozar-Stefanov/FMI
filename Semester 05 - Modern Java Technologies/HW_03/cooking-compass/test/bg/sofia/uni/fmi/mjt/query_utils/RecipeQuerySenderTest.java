package bg.sofia.uni.fmi.mjt.query_utils;

import bg.sofia.uni.fmi.mjt.RecipeQuery;
import bg.sofia.uni.fmi.mjt.exceptions.BadRecipeQueryException;
import bg.sofia.uni.fmi.mjt.exceptions.UnauthorizedQueryException;
import bg.sofia.uni.fmi.mjt.recipes.Recipe;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.http.HttpClient;
import java.net.http.HttpResponse;
import java.util.Collection;
import java.util.List;

import static org.mockito.ArgumentMatchers.any;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

public class RecipeQuerySenderTest {
    @Test
    public void testSendBadQuery() throws IOException, InterruptedException {
        HttpClient client = mock();
        HttpResponse response = mock();
        when(response.statusCode()).thenReturn(HttpURLConnection.HTTP_BAD_REQUEST);
        when(client.send(any(), any())).thenReturn(response);

        URI uri = URI.create("https://api.edamam.com/api/recipes/v2?type=public&q=chicken&app_id=test_id&app_key=test_key");

        Assertions.assertThrows(BadRecipeQueryException.class, () ->
            RecipeQuerySender.newSender(client).send(uri, 1),
            "Should handle invalid user request.");
    }

    @Test
    public void testSendWithInvalidKey() throws IOException, InterruptedException {
        HttpClient client = mock();
        HttpResponse response = mock();
        when(response.statusCode()).thenReturn(HttpURLConnection.HTTP_FORBIDDEN);
        when(client.send(any(), any())).thenReturn(response);

        URI uri = URI.create("https://api.edamam.com/api/recipes/v2?type=public&q=chicken&app_id=invalid_id&app_key=invalid_key");

        Assertions.assertThrows(UnauthorizedQueryException.class, () ->
            RecipeQuerySender.newSender(client).send(uri, 1),
            "Should handle invalid key or id.");
    }

    @Test
    public void testUnexpectedError() throws IOException, InterruptedException {
        HttpClient client = mock();
        HttpResponse response = mock();
        when(response.statusCode()).thenReturn(HttpURLConnection.HTTP_CLIENT_TIMEOUT);
        when(client.send(any(), any())).thenReturn(response);

        URI uri = URI.create("https://api.edamam.com/api/recipes/v2?type=public&q=chicken&app_id=test_id&app_key=test_key");

        Assertions.assertThrows(RuntimeException.class, () ->
            RecipeQuerySender.newSender(client).send(uri, 1),
            "Should handle unexpected errors.");
    }

    @Test
    public void testSuccessfulSend()
        throws IOException, InterruptedException, BadRecipeQueryException, UnauthorizedQueryException {
        HttpClient client = mock();
        URI uri = URI.create("https://api.edamam.com/api/recipes/v2?type=public&q=chicken&app_id=test_id&app_key=test_key");

        HttpResponse response01 = mock();
        when(response01.statusCode()).thenReturn(HttpURLConnection.HTTP_OK);
        when(response01.body()).thenReturn(TestRequestsRepository.PAGE_ONE_TEST_RESPONSE);

        when(client.send(any(), any())).thenReturn(response01);

        Collection<Recipe> recipes = RecipeQuerySender.newSender(client).send(uri, 1);

        Assertions.assertEquals(20, recipes.size(),
            "Number of read recipes from page is unexpected.");
        for (var recipe : recipes) {
            Assertions.assertTrue(recipe.label().matches("^.*[C|c]hicken.*$"),
                "Result does not match filter.");
        }
    }
}
