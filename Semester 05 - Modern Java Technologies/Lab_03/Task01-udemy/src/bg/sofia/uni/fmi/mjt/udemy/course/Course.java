package bg.sofia.uni.fmi.mjt.udemy.course;

import bg.sofia.uni.fmi.mjt.udemy.course.duration.CourseDuration;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotCompletedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.ResourceNotFoundException;

import java.util.Arrays;
import java.util.Objects;

public class Course implements Purchasable, Completable {
    private String name;
    private String description;
    private double price;
    private Resource[] content;
    private CourseDuration totalTime;
    private Category category;
    private boolean purchased;

    public Course(String name, String description, double price, Resource[] content, Category category) {
        this.name = name;
        this.description = description;
        this.price = price;
        this.content = content;
        this.totalTime = CourseDuration.of(content);
        this.category = category;
    }

    /**
     * Returns the name of the course.
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the description of the course.
     */
    public String getDescription() {
        return description;
    }

    /**
     * Returns the price of the course.
     */
    public double getPrice() {
        return price;
    }

    /**
     * Returns the category of the course.
     */
    public Category getCategory() {
        return category;
    }

    /**
     * Returns the content of the course.
     */
    public Resource[] getContent() {
        return content;
    }

    /**
     * Returns the total duration of the course.
     */
    public CourseDuration getTotalTime() {
        return totalTime;
    }

    /**
     * Completes a resource from the course.
     *
     * @param resourceToComplete the resource which will be completed.
     * @throws IllegalArgumentException  if resourceToComplete is null.
     * @throws ResourceNotFoundException if the resource could not be found in the course.
     */
    public void completeResource(Resource resourceToComplete) throws ResourceNotFoundException {
        if (resourceToComplete == null) {
            throw new IllegalArgumentException("Resource to complete cannot be null.");
        }
        for (var res : content) {
            if (res.equals(resourceToComplete)) {
                res.complete();
                return;
            }
        }

        throw new ResourceNotFoundException("Could not find resource in the course`s content.");
    }

    @Override
    public boolean isCompleted() {
        for (var res : content) {
            if (!res.isCompleted()) {
                return false;
            }
        }
        return true;
    }

    @Override
    public int getCompletionPercentage() {
        int completedResources = 0;
        for (var res : content) {
            if (res.isCompleted()) {
                completedResources++;
            }
        }
        return Math.round(((float) completedResources / content.length) * 100);
    }

    @Override
    public void purchase() {
        purchased = true;
    }

    @Override
    public boolean isPurchased() {
        return purchased;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Course course = (Course) o;
        return Double.compare(price, course.price) == 0 && Objects.equals(name, course.name) &&
            Objects.equals(description, course.description) && Arrays.equals(content, course.content) &&
            Objects.equals(totalTime, course.totalTime) && category == course.category;
    }

    @Override
    public int hashCode() {
        int result = Objects.hash(name, description, price, totalTime, category);
        result = 31 * result + Arrays.hashCode(content);
        return result;
    }
}
