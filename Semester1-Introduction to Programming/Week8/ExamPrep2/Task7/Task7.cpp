#include <iostream>

using namespace std;

int main()
{
    int n;
    int arr[50];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];

        if (num > max)
        {
            max = num;
        }
        if (num < min)
        {
            min = num;
        }
    }

    cout << min << endl;
    cout << max;
}