#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

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

int main()
{
    fstream numbersFile;
    numbersFile.open("chisla.txt");

    srand(time(NULL));
    int num;
    for (int i = 0; i < 100; i++)
    {
        num = rand() % 500 + 1;
        numbersFile << num << " ";
    }
    numbersFile.close();

    ofstream primesFile;
    primesFile.open("primes.txt", fstream::out);
    numbersFile.open("chisla.txt", fstream::in);

    string buffer;
    vector<int> numbers;

    while (getline(numbersFile, buffer));
    
    int temp = 0;
    for (int i = 0; i < buffer.size(); i++)
    {
        if (buffer[i] == ' ')
        {
            temp /= 10;
            numbers.push_back(temp);
            temp = 0;
        }
        else
        {
            temp += buffer[i] - '0';
            temp *= 10;
        }
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        if (isPrime(numbers[i]))
        {
            primesFile << numbers[i] << '\n';
        }
    }

    numbersFile.close();
    primesFile.close();
}
