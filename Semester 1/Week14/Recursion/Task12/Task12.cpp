#include <iostream>

bool isIncremental(const int arr[], const int size) 
{
	if (size == 2 && arr[size - 2] < arr[size - 1])
	{
		return true;
	}
	if (size == 2 && arr[size - 2] > arr[size - 1])
	{
		return false;
	}

	return (arr[size - 2] < arr[size - 1]) && isIncremental(arr, size - 1);
}

int main()
{
	int arr[] = { 2,1 };
    std::cout << isIncremental(arr,2);
}