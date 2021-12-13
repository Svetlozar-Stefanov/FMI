#include <iostream>

int main()
{
    int a = 5;
    int& rA = a;
    rA = 10;
    
    std::cout << a;
}