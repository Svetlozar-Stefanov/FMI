/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 5
* @compiler VC
*
*/


#include <iostream>

using namespace std;

int power(int const num, int const n)
{
    int output = 1;
    for (int i = 0; i < n; i++)
    {
        output *= num;
    }

    return output;
}

int main()
{
    double input;

    if (!(cin >> input) 
        || input < 0 
        || input - (int)input != 0)
    {
        cout << "-1";
        return 1;
    }
    unsigned int number = input;

    int temp = number;
    int digitCount = 0;

    while (temp > 0)
    {
        temp /= 10;
        digitCount++;
    }

    bool hasOddDigits = false;
    for (int i = digitCount; i >= 1; i--)
    {
        int currentDigit = (number % power(10, i)) / power(10, i - 1);

        if (currentDigit % 2 != 0)
        {
            cout << currentDigit;
            hasOddDigits = true;
        }
    }

    if (!hasOddDigits)
    {
        cout << "0";
    }
}
