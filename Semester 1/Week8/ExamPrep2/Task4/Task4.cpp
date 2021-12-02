#include <iostream>

using namespace std;

int digitCount(int num) 
{
    int count = 0;

    do
    {
        num /= 10;
        count++;
    } 
    while (num > 0);

    return count;
}

int getReverse(int num)
{
    int reverse = 0;
    int size = digitCount(num);
    for (int i = size - 1; i >= 0; i--)
    {
        int digit = num / (int)pow(10, i);
        num %= (int)pow(10, i);

        reverse += digit * (int)pow(10, size - 1 - i);
    }

    return reverse;
}

int main()
{
    int num;
    cin >> num;

    cout << getReverse(num);
}

