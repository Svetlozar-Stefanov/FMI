#include <iostream>

using namespace std;

int main()
{
    int arr1[100];
    int arr2[100];

    int n;

    cin >> n;

    if (n < 1 || n > 100)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr1[i] == arr2[i])
        {
            count++;
        }
    }

    cout << count;
}
