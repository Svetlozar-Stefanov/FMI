#include <iostream>

const int MAX_MEMBERS = 3;

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

struct Group
{
    Student students[MAX_MEMBERS];

    double avg;
};

Group createGroup() 
{
    Group newGroup;
    double avgGrade = 0;

    for (int i = 0; i < MAX_MEMBERS; i++)
    {
        int id;
        int y;
        double avg;

        std::cin >> id;
        std::cin >> y;
        std::cin >> avg;

        Year year = (Year)y;
        avgGrade += avg;

        newGroup.students[i] = initStudent(id, year, avg);
    }

    newGroup.avg = avgGrade / MAX_MEMBERS;

    return newGroup;
}

void printStudent(const Student& student)
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

    std::cout << " Avg: " << student.avgGrade << "\n";
}

int numOfScholarships(const Group& group, const double minGrade)
{
    int count = 0;
    for (int i = 0; i < MAX_MEMBERS; i++)
    {
        if (group.students[i].avgGrade >= minGrade)
        {
            count++;
        }
    }

    return count;
}

void printAllHonouraryStudents(const Group& group, const double minGrade)
{
    int numOfSh = numOfScholarships(group, minGrade);
    int* studentIndx = new int[numOfScholarships(group, numOfSh)];
    int index = 0;

    for (int i = 0; i < MAX_MEMBERS; i++)
    {
        if (group.students[i].avgGrade >= minGrade)
        {
            studentIndx[index++] = i;
        }
    }

    for (int i = 0; i < numOfSh; i++)
    {
        for (int j = 0; j < numOfSh - i - 1; j++)
        {
            if (group.students[studentIndx[j]].avgGrade < group.students[studentIndx[j + 1]].avgGrade)
            {
                std::swap(studentIndx[j], studentIndx[j + 1]);
            }
        }
    }

    for (int i = 0; i < numOfSh; i++)
    {
        printStudent(group.students[studentIndx[i]]);
    }

    delete[] studentIndx;
}

int main()
{
    Group group = createGroup();


    printAllHonouraryStudents(group, 4);
}