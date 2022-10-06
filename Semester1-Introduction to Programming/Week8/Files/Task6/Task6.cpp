#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> getParsedInfo(const string str, const char parseEl) 
{
    vector<string> words;
    string temp;
    for (int i = 0; i <= str.size(); i++)
    {
        if (str[i] != parseEl && str[i] != '\0')
        {
            temp += str[i];
        }
        else if(temp != "")
        {
            words.push_back(temp);
            temp = "";
        }
    }

    return words;
}

int getAsNumber(const string str) 
{
    int num = 0;
    for (int i = 0; i < str.size(); i++)
    {
        num += str[i] - '0';
        num *= 10;
    }
    num / 10;

    return num;
}

void createFile(fstream& file, const string fileName)
{
    file.open(fileName, fstream::out);
    if (!file.is_open())
    {
        cout << "Error";
        return;
    }
    file.close();
}

void addStudent(fstream& file, const string fileName, const string info)
{
    file.open(fileName, fstream::out | fstream::app);
    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    file << info << endl;
    file.close();
}

int getAbsenceSum(fstream& file, const string fileName)
{
    int sum = 0;

    file.open(fileName, fstream::in);
    if (!file.is_open())
    {
        cout << "Error";
        return -1;
    }

    string buffer;

    while (getline(file, buffer))
    {
        vector<string> currentStudent = getParsedInfo(buffer, ' ');
        sum += getAsNumber(currentStudent[2]);
        sum += getAsNumber(currentStudent[3]);
    }

    file.close();

    return sum;
}

vector<string> getStudentsWithMostAbsences(fstream& file, const string fileName)
{
    file.open(fileName, fstream::in);
    if (!file.is_open())
    {
        cout << "Error";
    }

    string buffer;

    int max = INT_MIN;
    vector<string> absentStudents;

    while (getline(file, buffer))
    {
        vector<string> currentStudent = getParsedInfo(buffer, ' ');
        int absences = getAsNumber(currentStudent[3]);
        if (absences > max)
        {
            max = absences;
            absentStudents.clear();
            absentStudents.push_back(buffer);
        }
        else if (absences == max)
        {
            absentStudents.push_back(buffer);
        }
    }

    file.close();

    return absentStudents;
}

void findStudent(fstream& fileManager, const string fileName, const string studentName)
{
    fileManager.open(fileName, fstream::in);

    if (!fileManager.is_open())
    {
        cout << "Error";
        return;
    }

    string buffer;
    while (getline(fileManager, buffer)) 
    {
        vector<string> currentStudent = getParsedInfo(buffer, '|');
        if (studentName == currentStudent[0])
        {
            cout << buffer;
            fileManager.close();
            return;
        }
    }

    cout << "Not found";
    fileManager.close();
}

void sortByName(fstream& file, const string fileName)
{
    file.open(fileName, fstream::in);

    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    vector<vector<string>> students;
    string buffer;
    while (getline(file, buffer))
    {
        students.push_back(getParsedInfo(buffer, '|'));
    }

    for (int i = students.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            string name1 = students[j][0];
            string name2 = students[j + 1][0];

            int index = 0;
            while (name1[index] < name2[index] 
                && index < name1.size() && index < name2.size())
            {
                index++;
            }
            if (name1[index] > name2[index])
            {
                vector<string> temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j < students[i].size(); j++)
        {
            file << students[i][j];
            if (j != students[i].size() - 1)
            {
                file << '|';
            }
        }
    }

    file.close();
}

void editStudent(fstream& file, const string fileName, const string student)
{
    file.open(fileName, fstream::in);

    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    string buffer;
    vector<vector<string>> students;
    while (getline(file, buffer))
    {
        vector<string> currentStudent = getParsedInfo(buffer, '|');
        if (student != currentStudent[0])
        {
            students.push_back(currentStudent);
        }
    }

    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j < students[i].size(); j++)
        {
            file << students[i][j];
            if (j != students[i].size() - 1)
            {
                file << '|';
            }
        }
    }

    file.close();
}

void editStudent(fstream& file, const string fileName, const string student, const string changes)
{
    file.open(fileName, fstream::in);

    if (!file.is_open())
    {
        cout << "Error";
        return;
    }

    string buffer;
    vector<vector<string>> students;
    while (getline(file, buffer))
    {
        vector<string> currentStudent = getParsedInfo(buffer, '|');
        if (student == currentStudent[0])
        {
            currentStudent = getParsedInfo(changes, '|');
            students.push_back(currentStudent);
        }
        else
        {
            students.push_back(currentStudent);
        }
    }

    for (int i = 0; i < students.size(); i++)
    {
        for (int j = 0; j < students[i].size(); j++)
        {
            file << students[i][j];
            if (j != students[i].size() - 1)
            {
                file << '|';
            }
        }
    }

    file.close();
}

void printFileInfo(fstream& fileManager, string fileName)
{
    fileManager.open(fileName, fstream::in);
    if (!fileManager.is_open())
    {
        cout << "Error";
        return;
    }
    string buffer;
    int i = 0;
    while (getline(fileManager, buffer))
    {
        cout << buffer;
    }
    cout << endl;

    fileManager.close();
}

int main()
{

}
