#include <iostream>

int main()
{
    std::cout << "Enter a letter: ";

    char input;
    std::cin >> input;

    int charNum = (int)input;

    if (charNum >= 65 && charNum <= 90)
    {
        std::cout << "The letter " << input << " is number " << charNum - (int)'A' + 1;
    }
}
