package bg.sofia.uni.fmi.mjt.udemy.exception;

public class CourseNotPurchasedException extends Exception {
    public CourseNotPurchasedException(String errorMessage)
    {
        super(errorMessage);
    }
}
