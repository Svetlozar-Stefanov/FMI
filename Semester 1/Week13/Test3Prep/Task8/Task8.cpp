#include <iostream>

int unevenIndexesSum(const int arr[], const unsigned size)
{
	if (arr == nullptr || size <= 0)
	{
		return -1;
	}

	if (size <= 3)
	{
		return 1;
	}

	int sum = 0;

	for (int i = 1; i < size; i+=2)
	{
		sum += arr[i];
	}

	return sum;
}

int main()
{
	int arr[] = { -2, 3, 5, -3, 2, 6 };

	std::cout << unevenIndexesSum(arr, 6);
}