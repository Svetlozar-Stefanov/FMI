#include <iostream>

using namespace std;

int main()
{
    int num;
    int output[20];

    cin >> num;

    int index = 0;
    while (num != 0)
    {
        output[index] = num % 2;
        num /= 2;
        index++;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        cout << output[i];
    }
}
