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
    cin >> num;

    cout << biggestDigit(num);
}

