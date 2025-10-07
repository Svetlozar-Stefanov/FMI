#include <iostream>

unsigned long long lastElement(unsigned long long * arr, const int size) 
{
    return *(arr + size - 1);
}

int main()
{
    unsigned long long arr[100];
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << lastElement(arr, n);
}