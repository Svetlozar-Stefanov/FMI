package bg.sofia.uni.fmi.mjt.udemy.account;

import bg.sofia.uni.fmi.mjt.udemy.account.type.AccountType;
import bg.sofia.uni.fmi.mjt.udemy.course.Category;
import bg.sofia.uni.fmi.mjt.udemy.course.Course;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseAlreadyPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.InsufficientBalanceException;
import bg.sofia.uni.fmi.mjt.udemy.exception.MaxCourseCapacityReachedException;

public class BusinessAccount extends AccountBase{
    private Category[] allowedCategories;
    public BusinessAccount(String username, double balance, Category[] allowedCategories) {
        super(username, balance);
        this.allowedCategories = allowedCategories;
        accountType = AccountType.BUSINESS;
    }

    @Override
    public void buyCourse(Course course) throws InsufficientBalanceException, CourseAlreadyPurchasedException, MaxCourseCapacityReachedException {
        boolean isInCategory = false;
        for(var category : allowedCategories)
        {
            if (course.getCategory() == category) { isInCategory = true; }
        }
        if(!isInCategory) { throw new IllegalArgumentException("Course not in the allowed category."); }

        double price = course.getPrice() - course.getPrice() * accountType.getDiscount();
        if(price > balance) { throw new InsufficientBalanceException("Balance not enough to buy course."); }
        for(int i = 0; i < size; i++)
        {
            if(courses[i].equals(course))
            {
                throw new CourseAlreadyPurchasedException("Course already owned.");
            }
        }
        if (size >= COURSE_CAPACITY) { throw new MaxCourseCapacityReachedException("Course capacity reached, cannot buy new courses."); }

        balance -= price;
        courses[size++] = course;
    }
}
