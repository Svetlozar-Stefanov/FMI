#include <iostream>

using namespace std;

int main()
{
    char arr[50];

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

    bool isSymetrical = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] != arr[n - i - 1])
        {
            isSymetrical = false;
            break;
        }
    }

    cout << isSymetrical;
}