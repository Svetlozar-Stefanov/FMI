#include <iostream>

using namespace std;

int main()
{
    int arr1[50];
    int arr2[50];

    int n;

    cin >> n;

    if (n < 1 || n > 50)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr1[i] * arr2[i];
    }
    
    cout << sum;
}
