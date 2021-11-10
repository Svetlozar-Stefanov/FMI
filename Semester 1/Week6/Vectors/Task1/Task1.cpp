#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> numbers;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += numbers[i];
    }

    cout << sum / n;
}
