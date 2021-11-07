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
    int index = n / 2;
    while (index > 0)
    {
        if (x == arr[index])
        {
            hasX = true;
            break;
        }
        else if (x < arr[index])
        {
            int temp = index - ((n - index) / 2);
            if (index == temp)
            {
                break;
            }
            index = temp;
        }
        else if (x > arr[index])
        {
            int temp = index + ((n - index) / 2);
            if (index == temp)
            {
                break;
            }
            index = temp;
        }
    }

    cout << hasX;
}