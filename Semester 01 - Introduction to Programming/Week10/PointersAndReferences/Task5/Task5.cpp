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

    int max = INT_MIN;
    int maxI = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxI = i;
        }
    }

    std::cout << &arr[maxI];
}