#include <iostream>

int smallestEvenNum(const int arr[], const unsigned size) 
{
	if (arr == nullptr || size <= 0)
	{
		return -1;
	}

	int min = INT_MAX;
	bool exists = false;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0 
			&& arr[i] < min)
		{
			min = arr[i];
			exists = true;
		}
	}

	if (!exists)
	{
		return 1;
	}

	return min;
}

int main()
{
	int arr[] = { -2,-3,5,-3,2 , 6};

	std::cout << smallestEvenNum(arr, 5);
}