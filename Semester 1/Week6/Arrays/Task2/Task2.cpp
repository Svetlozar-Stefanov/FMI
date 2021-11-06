#include <iostream>

using namespace std;

int main()
{
    int numbers[23];

    int n;

    cin >> n;

    if (n < 1 || n > 23)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int sum = 0;
    int negativeCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (numbers[i] > 0)
        {
            sum += numbers[i];
        }
        else if (numbers[i] < 0)
        {
            negativeCount++;
        }
    }

    cout << sum << endl;
    cout << negativeCount;
}
