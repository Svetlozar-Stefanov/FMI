#include <iostream>

void printDigits(const int num) 
{
    if (num == 0)
    {
        return;
    }
    std::cout << num % 10;

    return printDigits(num / 10);
}

int main()
{
    
}
