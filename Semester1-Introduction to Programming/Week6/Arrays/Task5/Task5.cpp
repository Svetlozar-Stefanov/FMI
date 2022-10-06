#include <iostream>

using namespace std;

int main()
{
    int numbers[50];

    int n;

    cin >> n;

    if (n < 1 || n > 50)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int max = INT_MIN;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        int currentNumber = numbers[i];

        if (currentNumber > max)
        {
            max = currentNumber;
            index = i;
        }
    }

    cout << max << endl;
    cout << index << endl;
}
