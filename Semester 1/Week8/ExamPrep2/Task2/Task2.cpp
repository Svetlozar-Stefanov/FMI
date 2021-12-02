#include <iostream>

using namespace std;

int smallestDigit(int num)
{
    int min = INT_MAX;

    do
    {
        int digit = num % 10;
        num /= 10;

        if (digit < min)
        {
            min = digit;
        }
    } 
    while (num > 0);

    return min;
}

int biggestDigit(int num)
{
    int max = INT_MIN;
    do
    {
        int digit = num % 10;
        num /= 10;

        if (digit > max)
        {
            max = digit;
        }
    } 
    while (num > 0);

    return max;
}

int main()
{
    int num;
    cin >> num;

    cout << smallestDigit(num) << endl;
    cout << biggestDigit(num);
}

