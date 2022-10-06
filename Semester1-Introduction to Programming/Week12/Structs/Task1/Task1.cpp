#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tourist {
    string name;
    unsigned yearOfBirth;
    string address;
};

bool containsStudentFromYear(vector<tourist>& students, unsigned year) 
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].yearOfBirth == year)
        {
            return true;
        }
    }

    return false;
}

void printAllBornBefore(vector<tourist>& students, unsigned year)
{
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].yearOfBirth < year)
        {
            cout << students[i].name << " " << students[i].address << '\n';
        }
    }
}

int main()
{
    vector<tourist> students =
    { {"Acho", 2003, "Burgas"},
        {"Guzi", 2000, "Ahtopol"},
        {"Andri", 2077, "Sofia"} };

    cout << containsStudentFromYear(students, 2000) << '\n';
    cout << containsStudentFromYear(students, 2004) << '\n';

    printAllBornBefore(students, 2077);
    printAllBornBefore(students, 2004);
}