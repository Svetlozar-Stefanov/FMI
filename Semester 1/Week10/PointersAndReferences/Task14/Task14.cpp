#include <iostream>

int trunk(float& num) 
{
    return num;
}

int main()
{
    float num = 2.534;

    std::cout << trunk(num);
}