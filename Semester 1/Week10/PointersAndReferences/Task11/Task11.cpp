#include <iostream>

int sizeOfArr(int* arr) 
{
    return sizeof(arr) / sizeof(arr[0]);
}

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

    std::cout << sizeOfArr(arrP) << '\n';
}