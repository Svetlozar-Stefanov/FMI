#include <iostream>

bool contains(const int arr[], const int size, const int k) 
{
	if (arr[size-1] == k)
	{
		return true;
	}

	if (size == 1)
	{
		return false;
	}

	return contains(arr, size - 1, k);
}

int main()
{
	int arr[] = { 1,23,4,2,5 };

    std::cout << contains(arr, 5, 6);
}