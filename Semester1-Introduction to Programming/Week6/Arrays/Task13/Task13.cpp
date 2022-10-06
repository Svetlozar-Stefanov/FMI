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

    int index;
    float newArr[50];

    for (int i = 0; i < n; i++)
    {
        index = 0;
        int currentNumber = arr[i];
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (currentNumber > arr[j])
                {
                    index++;
                }
                else if(currentNumber == arr[j] && i > j)
                {
                    index++;
                }
            }
        }

        newArr[index] = currentNumber;
    }

    for (int i = 0; i < n; i++)
    {
        cout << newArr[i] <<" ";
    }
}