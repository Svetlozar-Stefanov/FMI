#include <iostream>

bool hasMoreEvenNumbers(const int arr[], const unsigned size)
{
	if (arr == nullptr || size <= 0)
	{
		return false;
	}

	int evenCount = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] % 2 == 0)
		{
			evenCount++;
		}
	}

	return evenCount > size - evenCount;
}

int main()
{
	int arr[] = { -2, 3, 5 , 2, 6 };

	std::cout << hasMoreEvenNumbers(arr, 5);
}
