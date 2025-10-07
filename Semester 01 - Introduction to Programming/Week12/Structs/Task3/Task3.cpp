#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct tourist {
    string name;
    float gradeFirstSem;
    float gradeSecondSem;
};

int main()
{
    int n;
    cin >> n;

    vector<tourist> students;
    for (int i = 0; i < n; i++)
    {
        tourist temp;
        cin >> temp.name;
        cin >> temp.gradeFirstSem;
        cin >> temp.gradeSecondSem;

        students.push_back(temp);
    }

    float minGrade = 6;
    tourist worstStudent;

    float maxGrade = 2;
    tourist bestStudent;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].gradeFirstSem < minGrade)
        {
            minGrade = students[i].gradeFirstSem;
            worstStudent = students[i];
        }

        if ((students[i].gradeFirstSem + students[i].gradeSecondSem) / 2 
        > maxGrade)
        {
            maxGrade = (students[i].gradeFirstSem + students[i].gradeSecondSem) / 2;
            bestStudent = students[i];
        }
    }

    cout << minGrade << worstStudent.name << '\n';
    cout << maxGrade << bestStudent.name << '\n';
}
