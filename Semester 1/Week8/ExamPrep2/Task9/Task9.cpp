#include <iostream>

using namespace std;

void reverse(const int n, int arr[]) 
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
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

    reverse(n, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}