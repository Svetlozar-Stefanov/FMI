#include <iostream>

using namespace std;

int biggestDigit(int num)
{
    int sum = 0;

    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int main()
{
    int num;
    int digitRepetitions[10] = {};
    cin >> num;

    do
    {
        int digit = num % 10;
        digitRepetitions[digit]++;

        num /= 10;
    } 
    while (num > 0);

    for (int i = 0; i < 10; i++)
    {
        if (digitRepetitions[i] > 0)
        {
            cout << i << " - " << digitRepetitions[i] << endl;
        }
    }
}

