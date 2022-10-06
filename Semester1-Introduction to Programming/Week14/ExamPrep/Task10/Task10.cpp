#include <iostream>

int getSum(const int arr[], const int size)
{
	if (arr == nullptr)
	{
		return -1;
	}

	int sum = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int analyzeArray(const int arr[], const int size) 
{
	if (arr == nullptr)
	{
		return -1;
	}

	int sum = getSum(arr, size);

	if (sum % 2 != 0)
	{
		return 0;
	}

	int searchedSum = sum / 2;

	for (int i = 0; i < size; i++)
	{
		int tempSum = 0;
		for (int j = i; j < size; j++)
		{
			tempSum += arr[j];
			if (tempSum == searchedSum)
			{
				return 1;
			}
			if (tempSum > searchedSum)
			{
				break;
			}
		}
	}

	return 0;
}

int main()
{
	int arr[] = { 1,6,1,0,5,199 };
	std::cout << analyzeArray(arr, 5);
}