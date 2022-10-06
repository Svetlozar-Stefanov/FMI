#include <iostream>

using namespace std;

int digitCount(int num)
{
    int count = 0;

    do
    {
        num /= 10;
        count++;
    } while (num > 0);

    return count;
}

bool isPalindrome(int num) 
{
    int size = digitCount(num);

    bool palindrome = true;

    for (int i = 0; i < size / 2; i++)
    {
        int firstD = (num / (int)pow(10, size - 1 - i)) % 10;
        int lastD = (num / (int)pow(10, i)) % 10;

        if (firstD != lastD)
        {
            palindrome = false;
            return palindrome;
        }
    }

    return palindrome;
}

int main()
{
    int num;
    cin >> num;

    cout << isPalindrome(num);
}

