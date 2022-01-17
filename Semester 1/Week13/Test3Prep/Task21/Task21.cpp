#include <iostream>

void printHours(const unsigned seconds) 
{
    unsigned minutes = (seconds / 60) % 60;

    unsigned hours = (seconds / 3600);

    if (hours < 10)
    {
        std::cout << '0';
    }
    std::cout << hours;
    std::cout << ':';
    if (minutes < 10)
    {
        std::cout << '0';
    }
    std::cout << minutes;
}

int main()
{
    printHours(48000);
}