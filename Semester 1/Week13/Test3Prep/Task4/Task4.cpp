#include <iostream>

int biggestUnevenNum(const int arr[], const unsigned size)
{
	if (arr == nullptr || size <= 0)
	{
		return -1;
	}

	int max = INT_MIN;
	bool exists = false;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 != 0
			&& arr[i] > max)
		{
			max = arr[i];
			exists = true;
		}
	}

	if (!exists)
	{
		return 0;
	}

	return max;
}

int main()
{
	int arr[] = { 2,-3,5,-3,2 };

	std::cout << biggestUnevenNum(arr, 5);
}