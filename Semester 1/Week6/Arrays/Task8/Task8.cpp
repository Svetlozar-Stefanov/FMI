#include <iostream>

using namespace std;

int main()
{
    int arr[50];

    int n;
    int x;

    cin >> n;

    if (n < 1 || n > 50)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> x;

    bool hasX = false;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            hasX = true;
            break;
        }
    }

    cout << hasX;
}

