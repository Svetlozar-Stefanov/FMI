#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tourist {
    unsigned classId;
    string name;
    float grade;
};

int main()
{
    int n;
    cin >> n;

    vector<tourist> students;
    for (int i = 0; i < n; i++)
    {
        tourist temp;
        cin >> temp.classId;
        cin >> temp.name;
        cin >> temp.grade;

        students.push_back(temp);
    }

    int countFailed = 0;
    float sum = 0;
    float highestGrade = 2;
    int stWithHighestGrade = 0;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].grade > 5.50)
        {
            cout << students[i].name << '\n';
        }
        if (students[i].grade < 3.00)
        {
            countFailed++;
        }

        sum += students[i].grade;

        if (highestGrade < students[i].grade)
        {
            highestGrade = students[i].grade;
            stWithHighestGrade = 1;
        }
        else if (highestGrade == students[i].grade)
        {
            stWithHighestGrade++;
        }
    }

    cout << countFailed << '\n';
    float avg = sum / n;
    cout << avg << '\n';
    cout << highestGrade << "-" << stWithHighestGrade << '\n';

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].grade > avg)
        {
            cout << students[i].name << '\n';
        }
    }
    
}
    