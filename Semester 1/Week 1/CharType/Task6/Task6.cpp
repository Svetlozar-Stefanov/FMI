#include <cmath>
#include <iostream>
#include <string>
using namespace std;


int main()
{
    const int numberLength = 3;
    
    string input1;
    string input2;


    cout << "First number:\n";
    cin >> input1;

    if (input1.size() != numberLength)
    {
        return 0;
    }

    std::cout << "Second number:\n";
    std::cin >> input2;

    if (input2.size() != numberLength)
    {
        return 0;
    }

    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < numberLength; i++)
    {
        if (48 <= input1[i] && input1[i] <= 57
            && 48 <= input2[i] && input2[i] <= 57)
        {
            num1 += (int)(input1[i] - '0') * pow(10, numberLength - i - 1);
            num2 += (int)(input2[i] - '0') * pow(10, numberLength - i - 1);
        }
        else
        {
            return 0;
        }
    }
    std::cout << num1 + num2;
}
