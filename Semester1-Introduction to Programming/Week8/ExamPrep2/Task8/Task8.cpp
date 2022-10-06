#include <iostream>

using namespace std;

void orderByIncrease(const int n, int arr[]) 
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void orderByDecrease(const int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
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

    orderByDecrease(n, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}