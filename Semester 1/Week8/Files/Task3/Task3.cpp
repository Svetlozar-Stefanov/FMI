#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isPrime(const int num)
{
    bool prime = true;
    if (num == 2)
    {
        prime = false;
        return prime;
    }

    for (int i = 2; i < num; i++)
    {
        if (i != num && num % i == 0)
        {
            prime = false;
            break;
        }
    }

    return prime;
}

void createFileWithPrimesInInterval( fstream & fileManager, const string & fileName, const unsigned interval) 
{
    fileManager.open(fileName, fstream::out);
    if (!fileManager.is_open())
    {
        cout << "Error";
        return;
    }

    for (int i = 1; i <= interval; i++)
    {
        if (isPrime(i))
        {
            fileManager << i << " ";
        }
    }

    fileManager.close();
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
    fstream numbersFile;
    createFileWithPrimesInInterval(numbersFile, "primes.txt", 500);
    printFileInfo(numbersFile, "primes.txt");
}


