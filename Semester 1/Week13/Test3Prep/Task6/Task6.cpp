#include <iostream>

int positiveEvenSum(const int arr[], const unsigned size) 
{
	if (arr == nullptr || size <= 0)
	{
		return -1;
	}

    int sum = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0 && arr[i] % 2 == 0)
		{
			sum += arr[i];
		}
	}

	return sum;
}

int main()
{
	int arr[] = { -2,-3,5,-3,2 , 6 };

	std::cout << positiveEvenSum(arr, 6);
}