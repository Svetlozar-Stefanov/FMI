#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int GetSum(string input);

int main()
{
    string input1;
    string input2;

    cin >> input1;
    cin >> input2;

    int sum1 = 0;
    int sum2 = 0;

    sum1 = GetSum(input1);
    sum2 = GetSum(input2);

    if (sum1 > sum2)
    {
        cout << input1 << " " << sum1;
    }
    else if (sum1 < sum2)
    {
        cout << input2 << " " << sum2;
    }
    else
    {
        cout << 0;
    }

}

int GetSum(string input)
{
    int sum = 0;

    for (int i = 0; i < 4; i++)
    {
        if (input[i] >= 97 && input[i] <= 122)
        {
            sum += input[i] - 'a' + 1;
        }
        else if (input[i] >= 65 && input[i] <= 90)
        {
            sum += 2 * (input[i] - 'A' + 1);
        }
        else if (input[i] >= 48 && input[i] <= 57)
        {
            sum += input[i] - '0';
        }
    }

    return sum;
}
