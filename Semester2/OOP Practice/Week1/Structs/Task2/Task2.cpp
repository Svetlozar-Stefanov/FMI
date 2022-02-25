#include <iostream>

enum Year
{
    First = 1,
    Second,
    Third,
    Fourth
};

struct Student
{
    unsigned id;
    Year year;
    double avgGrade;
};

Student initStudent(const unsigned id, const Year year, const double avg) 
{
    Student newStudent;
    newStudent.id = id;
    newStudent.year = year;
    newStudent.avgGrade = avg;

    return newStudent;
}

void printStudent(const Student student) 
{
    std::cout << "ID: " << student.id << " Year: ";
    switch (student.year)
    {
    case First: std::cout << "First"; break;
    case Second: std::cout << "Second"; break;
    case Third: std::cout << "Third"; break;
    case Fourth: std::cout << "Fourth"; break;
    default: std::cout << "error";
        break;
    }

    std::cout << " Avg: "<< student.avgGrade;
}

int main()
{
    std::cout << "Hello World!\n";
}