package bg.sofia.uni.fmi.mjt.udemy.account;

import bg.sofia.uni.fmi.mjt.udemy.account.type.AccountType;
import bg.sofia.uni.fmi.mjt.udemy.course.Course;
import bg.sofia.uni.fmi.mjt.udemy.exception.CourseAlreadyPurchasedException;
import bg.sofia.uni.fmi.mjt.udemy.exception.InsufficientBalanceException;
import bg.sofia.uni.fmi.mjt.udemy.exception.MaxCourseCapacityReachedException;

public class EducationalAccount extends AccountBase{
    private int startIndex = 0;
    public EducationalAccount(String username, double balance) {
        super(username, balance);
        accountType = AccountType.EDUCATION;
    }
    @Override
    public void buyCourse(Course course) throws InsufficientBalanceException, CourseAlreadyPurchasedException, MaxCourseCapacityReachedException {
        short promo = 0;
        if(numberOfGrades >= 5)
        {
            while (startIndex <= numberOfGrades-5)
            {
                double avgGrade = 0.0;
                for(int i = startIndex; i < startIndex + 5; i++)
                {
                    avgGrade += grades[i];
                }
                avgGrade /= 5.0;
                if(avgGrade >= 4.5)
                {
                    promo = 1;
                    startIndex += 5;
                    break;
                }
                startIndex++;
            }
        }

        double price = course.getPrice() - promo * (course.getPrice() * accountType.getDiscount());
        if(price  > balance) { throw new InsufficientBalanceException("Balance not enough to buy course."); }
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
