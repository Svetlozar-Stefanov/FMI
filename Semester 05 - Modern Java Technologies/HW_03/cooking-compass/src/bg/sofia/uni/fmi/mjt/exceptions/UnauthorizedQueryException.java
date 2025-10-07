package bg.sofia.uni.fmi.mjt.exceptions;

public class UnauthorizedQueryException extends Exception {
    public UnauthorizedQueryException(String message) {
        super(message);
    }

    public UnauthorizedQueryException(String message, Throwable cause) {
        super(message, cause);
    }
}
