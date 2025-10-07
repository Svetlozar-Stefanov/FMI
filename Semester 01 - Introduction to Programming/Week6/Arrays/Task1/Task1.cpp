#include <iostream>

using namespace std;

int main()
{
    int grades[50];

    int n;

    cin >> n;

    if (n < 1 || n > 50)
    {
        return 1;
    }
    
    for (int i = 0; i < n; i++)
    {
        cin >> grades[i];
    }

    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += grades[i];
    }

    cout << sum / n;
}
