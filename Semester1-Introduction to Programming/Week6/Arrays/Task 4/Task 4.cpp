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

    int min = INT_MAX;
    int max = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int currentNumber = numbers[i];

        if (currentNumber > max)
        {
            max = currentNumber;
        }
        if (currentNumber < min)
        {
            min = currentNumber;
        }
    }

    cout << max << endl;
    cout << min << endl;
}
