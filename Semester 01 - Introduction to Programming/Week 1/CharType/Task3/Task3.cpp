#include <iostream>

int main()
{
    char firstLetter;
    char secondLetter;

    std::cout << "First letter: ";
    std::cin >> firstLetter;

    std::cout << "\nSecond letter: ";
    std::cin >> secondLetter;

    if (65 <= firstLetter && firstLetter <= 90
        && 65 <= secondLetter && secondLetter <= 90)
    {
        std::cout << firstLetter + secondLetter;
    }

}
