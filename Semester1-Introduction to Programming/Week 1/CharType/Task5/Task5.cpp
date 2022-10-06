#include <iostream>

int main()
{
    char firstNumber;
    char secondNumber;

    std::cout << "First number: ";
    std::cin >> firstNumber;

    std::cout << "Second number: ";
    std::cin >> secondNumber;

    if (48 <= firstNumber && firstNumber <= 57
        && 48 <= secondNumber && secondNumber <= 57)
    {
        int num1 = firstNumber - '0';
        int num2 = secondNumber - '0';
        std::cout <<  num1 * num2;
    }
}
