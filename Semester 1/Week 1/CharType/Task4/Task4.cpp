#include <iostream>

int main()
{
    char input;
    
    std::cout << "Enter a letter: ";
    std::cin >> input;

    if (65 <= input && input <= 90)
    {
        char output = (int)'Z' - ((int)input - (int)'A');
        std::cout <<output;
    }
}
