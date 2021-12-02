#include <iostream>

using namespace std;

bool isPalindrome(const int n, const int arr[]) 
{
    bool palindrome = true;

    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - 1 - i])
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
    int arr[50];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << isPalindrome(n, arr);
}