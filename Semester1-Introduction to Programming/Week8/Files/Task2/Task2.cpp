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

void getPositiveNumFromFile(fstream & numbersFile, string numFileName,
    fstream & positiveNumbersFile, string pnumFileName)
{
    numbersFile.open(numFileName, fstream::in);
    if (!numbersFile.is_open())
    {
        cout << "Error";
        return;
    }

    positiveNumbersFile.open(pnumFileName, fstream::out);
    if (!positiveNumbersFile.is_open())
    {
        cout << "Error";
        return;
    }

    string buffer;
    string buffer2;
    int index = 0;
    while (getline(numbersFile, buffer));


    for (int i = 0; i < buffer.size(); i++)
    {
        if (buffer[i] == '-')
        {
            while (buffer[i] != ' ')
            {
                i++;
            }
            continue;
        }

        buffer2 += buffer[i];
    }

    positiveNumbersFile << buffer2;

    numbersFile.close();
    positiveNumbersFile.close();
}

void printFileInfo(fstream & fileManager, string fileName) 
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

    fileManager.close();
}

int main()
{

    fstream numFile;
    fstream posNumFile;

    createFile(numFile, "numbers.txt", 500);
    getPositiveNumFromFile(numFile, "numbers.txt", posNumFile, "posNum.txt");
    printFileInfo(numFile, "numbers.txt");
    cout << endl;
    printFileInfo(posNumFile, "posNum.txt");
    
}
