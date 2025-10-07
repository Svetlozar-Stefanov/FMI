package bg.sofia.uni.fmi.mjt.udemy.account;

import bg.sofia.uni.fmi.mjt.udemy.account.type.AccountType;
import bg.sofia.uni.fmi.mjt.udemy.course.Course;
import bg.sofia.uni.fmi.mjt.udemy.course.Resource;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseAlreadyPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotCompletedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.InsufficientBalanceException;
import bg.sofia.uni.fmi.mjt.udemy.exception.MaxCourseCapacityReachedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.ResourceNotFoundException;

public abstract class AccountBase implements Account{

    protected static final int COURSE_CAPACITY = 100;

    protected AccountType accountType;
    protected String username;
    protected double balance;
    protected int size;
    protected Course[] courses;

    protected double[] grades;
    protected int numberOfGrades;

    public AccountBase(String username, double balance)
    {
        this.username = username;
        this.balance = balance;
        size = 0;
        courses = new Course[COURSE_CAPACITY];
        numberOfGrades = 0;
        grades = new double[COURSE_CAPACITY];
    }

    @Override
    public String getUsername() {
        return username;
    }

    @Override
    public void addToBalance(double amount) {
        if(amount <= 0) { throw new IllegalArgumentException("Cannot add negative amount of money to account."); }

        balance += amount;
    }

    @Override
    public double getBalance() {
        return balance;
    }

    @Override
    public void buyCourse(Course course) throws InsufficientBalanceException, CourseAlreadyPurchasedException, MaxCourseCapacityReachedException {
        if(course.getPrice() > balance) { throw new InsufficientBalanceException("Balance not enough to buy course."); }
        for(int i = 0; i < size; i++)
        {
            if(courses[i].equals(course))
            {
                throw new CourseAlreadyPurchasedException("Course already owned.");
            }
        }
        if (size >= COURSE_CAPACITY) { throw new MaxCourseCapacityReachedException("Course capacity reached, cannot buy new courses."); }

        balance -= course.getPrice();
        courses[size++] = course;
    }

    @Override
    public void completeResourcesFromCourse(Course course, Resource[] resourcesToComplete) throws CourseNotPurchasedException, ResourceNotFoundException {
        for(int i = 0; i < size; i++)
        {
            if(courses[i].equals(course))
            {
                for(var resource : resourcesToComplete)
                {
                    courses[i].completeResource(resource);
                }
                return;
            }
        }
        throw new CourseNotPurchasedException("Course is not owned by this account.");
    }

    @Override
    public void completeCourse(Course course, double grade) throws CourseNotPurchasedException, CourseNotCompletedException {
        for(int i = 0; i < size; i++)
        {
            if(courses[i].equals(course))
            {
                if(!courses[i].isCompleted())
                {
                    throw new CourseNotCompletedException("Not all resources in course are complete.");
                }
                grades[numberOfGrades++] = grade;
                return;
            }
        }
        throw new CourseNotPurchasedException("Course is not owned by this account.");
    }

    @Override
    public Course getLeastCompletedCourse() {
        if(size == 0)
        {
            return null;
        }
        Course least = courses[0];
        for(int i = 1; i < size; i++)
        {
            if(least.getCompletionPercentage() > courses[i].getCompletionPercentage())
            {
                least = courses[i];
            }
        }
        return least;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }

        if (obj.getClass() != this.getClass()) {
            return false;
        }

        final AccountBase other = (AccountBase) obj;
        if ((this.username == null) ? (other.username != null) : !this.username.equals(other.username)) {
            return false;
        }

        return true;
    }

    @Override
    public int hashCode() {
        int hash = 3;
        hash = 53 * hash + (this.username != null ? this.username.hashCode() : 0);
        return hash;
    }
}
