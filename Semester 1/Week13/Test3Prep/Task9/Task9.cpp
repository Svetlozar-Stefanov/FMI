#include <iostream>

int firstAndLastSum(const int arr[], unsigned int size) 
{
    if (arr == nullptr || size <= 0)
    {
        return -1;
    }

    return arr[0] + arr[size - 1];
}

int main()
{
    int arr[] = { -2, 3, 5, -3, 2, 6 };

    std::cout << firstAndLastSum(arr, 6);
}