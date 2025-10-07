package bg.sofia.uni.fmi.mjt.udemy.course.duration;
import bg.sofia.uni.fmi.mjt.udemy.course.Resource;

public record CourseDuration(int hours, int minutes) {
    public CourseDuration {
        if(hours < 0 || hours > 24)
        {
            throw new IllegalArgumentException("Hours must be in the [0,24] interval.");
        }
        if(minutes < 0 || minutes > 60)
        {
            throw new IllegalArgumentException("Minutes must be in the [0,60] interval.");
        }
    }
    public static CourseDuration of(Resource[] content)
    {
        int minutes = 0;
        for(var res : content)
        {
            minutes += res.getDuration().minutes();
        }
        return new CourseDuration(minutes / 60, minutes % 60);
    }
}
