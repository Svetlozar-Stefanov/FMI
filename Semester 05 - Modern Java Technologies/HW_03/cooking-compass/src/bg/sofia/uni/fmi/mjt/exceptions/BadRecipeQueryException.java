package bg.sofia.uni.fmi.mjt.exceptions;

public class BadRecipeQueryException extends Exception {
    public BadRecipeQueryException(String message) {
        super(message);
    }

    public BadRecipeQueryException(String message, Throwable cause) {
        super(message, cause);
    }
}
