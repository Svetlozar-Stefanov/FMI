package bg.sofia.uni.fmi.mjt.exceptions;

public class NoFiltersAppliedException extends Exception {
    public NoFiltersAppliedException(String message) {
        super(message);
    }

    public NoFiltersAppliedException(String message, Throwable cause) {
        super(message, cause);
    }
}
