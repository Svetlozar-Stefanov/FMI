#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void createFile(fstream& numbersFile, string numFileName, const int interval)
{
    numbersFile.open(numFileName, fstream::out);

    if (!numbersFile.is_open())
    {
        cout << "Error";
        return;
    }

    vector<int> fibSeq;
    fibSeq.push_back(1);
    int index = 0;
    numbersFile << fibSeq[index] << ' ';

    while (fibSeq[index] < interval)
    {
        if (index < 1)
        {
            fibSeq.push_back(1);
            index++;
            numbersFile << fibSeq[index] << ' ';
        }
        else
        {
            fibSeq.push_back(fibSeq[index] + fibSeq[index - 1]);
            index++;
            numbersFile << fibSeq[index] << ' ';
        }
    }

    numbersFile.close();
}

bool findStudent(fstream& fileManager, string fileName, string k)
{
    fileManager.open(fileName, fstream::in);

    if (!fileManager.is_open())
    {
        cout << "Error";
        return false;
    }

    string buffer;
    while (getline(fileManager, buffer));

    int index = 0;
    for (int i = 0; i < buffer.size(); i++)
    {
        
        if (k[index] == buffer[i])
        {
            index++;
        }

        if (index == k.size() - 1)
        {
            return true;
        }
    }

    fileManager.close();

    return false;
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
    fstream numFile;
    string input;
    do
    {
        cin >> input;

        if (input == "create")
        {
            string fileName;
            cin >> fileName;
            int interval;
            cin >> interval;
            createFile(numFile, fileName, interval);
        }
        else if (input == "print")
        {
            string fileName;
            cin >> fileName;
            printFileInfo(numFile, fileName);
        }
        else if (input == "find")
        {
            string fileName;
            cin >> fileName;
            string num;
            cin >> num;
            cout << findStudent(numFile, fileName, num);
            cout << endl;
        }

    } while (input != "end");

}
