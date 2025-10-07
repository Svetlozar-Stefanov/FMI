#include <iostream>

void swap(int * a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 10;
    int b = 15;

    int* aP = &a;
    int* bP = &b;

    swap(aP, bP);
    std::cout << a << " " << b;
}
