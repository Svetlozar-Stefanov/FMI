#include <iostream>

using namespace std;

int main()
{
    int arr[50];

    int n;

    cin >> n;

    if (n < 1 || n > 50)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }


    bool isDecremental = false;
    for (int i = 0; i < n - 1; i++)
    {
        isDecremental = true;

        if (!(arr[i] > arr[i + 1]))
        {
            isDecremental = false;
            break;
        }
    }

    cout << isDecremental;
}