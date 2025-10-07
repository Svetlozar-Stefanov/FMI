package bg.sofia.uni.fmi.mjt.udemy;

import bg.sofia.uni.fmi.mjt.udemy.account.Account;
import bg.sofia.uni.fmi.mjt.udemy.course.Category;
import bg.sofia.uni.fmi.mjt.udemy.course.Course;
import bg.sofia.uni.fmi.mjt.udemy.exception.AccountNotFoundException;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseNotFoundException;

import java.util.Arrays;

public class Udemy implements LearningPlatform{
    private Account[] accounts;
    private Course[] courses;

    public Udemy(Account[] accounts, Course[] courses)
    {
        this.accounts = accounts;
        this.courses = courses;
    }

    @Override
    public Course findByName(String name) throws CourseNotFoundException {
        if(name == null) { throw new IllegalArgumentException("Name cannot be null."); }

        for(var course : courses)
        {
            if(course.getName() == name)
            {
                return course;
            }
        }
        throw new CourseNotFoundException("Course could not be found.");
    }

    @Override
    public Course[] findByKeyword(String keyword) {
        if(keyword == null
        || keyword.equals("")
        || !keyword.matches("^[a-zA-Z]+$"))
        {
            throw new IllegalArgumentException("Keyword is not in valid format.");
        }

        Course[] coursesByKeyword = new Course[courses.length];
        int size = 0;

        for(var course : courses)
        {
            if(course.getName().contains(keyword) || course.getDescription().contains(keyword))
            {
                coursesByKeyword[size++] = course;
            }
        }
        return Arrays.copyOf(coursesByKeyword, size);
    }

    @Override
    public Course[] getAllCoursesByCategory(Category category) {
        if(category == null)
        {
            throw new IllegalArgumentException("Category cannot be null.");
        }

        Course[] coursesByKeyword = new Course[courses.length];
        int size = 0;

        for(var course : courses)
        {
            if(course.getCategory() == category)
            {
                coursesByKeyword[size++] = course;
            }
        }
        return Arrays.copyOf(coursesByKeyword, size);
    }

    @Override
    public Account getAccount(String name) throws AccountNotFoundException {
        if(name == null
        || name.equals(""))
        {
            throw new IllegalArgumentException("Name cannot be null or blank.");
        }

        for(var account : accounts)
        {
            if(account.getUsername().equals(name))
            {
                return account;
            }
        }
        throw new AccountNotFoundException("There is no account with this name.");
    }

    @Override
    public Course getLongestCourse() {
        if(courses.length == 0)
        {
            return null;
        }

        Course longest = courses[0];
        for(int i = 1; i < courses.length; i++)
        {
            if(longest.getTotalTime().hours() < courses[i].getTotalTime().hours()
            || (longest.getTotalTime().hours() == courses[i].getTotalTime().hours()
            && longest.getTotalTime().hours() < courses[i].getTotalTime().hours()))
            {
                longest = courses[i];
            }
        }
        return longest;
    }

    @Override
    public Course getCheapestByCategory(Category category) {
        if(category == null)
        {
            throw new IllegalArgumentException("Category cannot be null.");
        }

        Course[] coursesByCategory = getAllCoursesByCategory(category);
        if(coursesByCategory.length == 0) { return null; }
        Course cheapest = courses[0];
        for(int i = 1; i < coursesByCategory.length; i++)
        {
            if(cheapest.getPrice() > courses[i].getPrice())
            {
                cheapest = courses[i];
            }
        }
        return cheapest;
    }
}
