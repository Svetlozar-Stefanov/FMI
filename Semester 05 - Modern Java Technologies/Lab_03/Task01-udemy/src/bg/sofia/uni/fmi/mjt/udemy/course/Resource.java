package bg.sofia.uni.fmi.mjt.udemy.course;

import bg.sofia.uni.fmi.mjt.udemy.course.duration.ResourceDuration;

public class Resource implements Completable{
    private String name;
    private ResourceDuration duration;
    private int completion;
    private boolean isFinished;

    public Resource(String name, ResourceDuration duration)
    {
        this.name = name;
        this.duration = duration;
        this.completion = 0;
        this.isFinished = false;
    }

    /**
     * Returns the resource name.
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the total duration of the resource.
     */
    public ResourceDuration getDuration() {
        return duration;
    }

    /**
     * Marks the resource as completed.
     */
    public void complete() {
        completion = 100;
        isFinished = true;
    }

    @Override
    public boolean isCompleted() {
        return isFinished;
    }

    @Override
    public int getCompletionPercentage() {
        return completion;
    }
}
