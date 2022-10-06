#include <iostream>

int main()
{
    int arr[100];

    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    int* arrP = arr;
    for (int i = 0; i < n; i++)
    {
        std::cout << *(arrP + i);
    }
}