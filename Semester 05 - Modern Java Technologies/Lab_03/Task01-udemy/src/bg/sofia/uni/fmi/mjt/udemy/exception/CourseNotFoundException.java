package bg.sofia.uni.fmi.mjt.udemy.exception;

public class CourseNotFoundException extends Exception {
    public CourseNotFoundException(String errorMessage)
    {
        super(errorMessage);
    }
}
