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
    int start = 0;
    int end = n;
    int index = end / 2;
    while (true)
    {
        if (x == arr[index])
        {
            hasX = true;
            break;
        }
        else if (x < arr[index])
        {
            end = index;
            int temp = start + (end - start) / 2;
            if (temp == index)
            {
                break;
            }
            index = temp;
        }
        else if (x > arr[index])
        {
            start = index;
            int temp = start + (end - start) / 2;
            if (temp == index)
            {
                break;
            }
            index = temp;
        }
    }

    cout << hasX;
}