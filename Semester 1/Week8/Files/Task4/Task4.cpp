#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

void createFile(fstream& numbersFile, string numFileName, const int interval)
{
    numbersFile.open(numFileName, fstream::out);

    if (!numbersFile.is_open())
    {
        cout << "Error";
        return;
    }

    srand(time(NULL));
    int num;
    for (int i = 0; i < 100; i++)
    {
        num = (rand() % interval - interval / 2);
        numbersFile << num << ' ';
    }
    numbersFile.close();
}

void containsK(fstream& fileManager, string fileName, int number) 
{
    fileManager.open(fileName, fstream::out | fstream::app);

    if (!fileManager.is_open())
    {
        cout << "Error";
        return;
    }

    fileManager << number << " ";

    fileManager.close();
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
        else if (input == "add")
        {
            string fileName;
            cin >> fileName;
            int num;
            cin >> num;
            containsK(numFile, fileName, num);
        }

    } while (input != "end");

}
