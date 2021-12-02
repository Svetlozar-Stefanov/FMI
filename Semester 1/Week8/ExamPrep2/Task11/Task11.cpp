#include <iostream>

using namespace std;

int main()
{
    int n;
    int arr1[50];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    int m;
    int arr2[50];

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                cout << true;
                return 0;
            }
        }
    }

    cout << false;
}