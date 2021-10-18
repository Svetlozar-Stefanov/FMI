#include <iostream>
int main()
{
    std::cout << "Enter a number form 0 to 255: ";

    int input;
    std::cin >> input;

    if (0 <= input && input <= 255)
    {
        std::cout << "The ASCII representation of this number is: " << (char)input << std::endl;
    }
    else
    {
        std::cout << "Invalid input";
    }
}
