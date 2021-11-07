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

    bool isUnrepeating = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                isUnrepeating = false;
                break;
            }
        }
    }

    cout << isUnrepeating;
}