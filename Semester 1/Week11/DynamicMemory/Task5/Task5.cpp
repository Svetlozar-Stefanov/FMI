#include <iostream>

using namespace std;

bool isPalindrome(const char* arr, const int size)
{
    bool palindrome = true;

    for (int i = 0; i < size / 2; i++)
    {
        if (arr[i] != arr[size - i])
        {
            palindrome = false;
            break;
        }
    }

    return palindrome;
}

int main()
{
    int n;
    cin >> n;

    char* arr = new char[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << isPalindrome(arr, n);

    delete[] arr;
}