#include <iostream>

bool isInDescendingOrder(const int arr[], const unsigned size) 
{
	if (arr == nullptr || size <= 0)
	{
		return false;
	}

	for (int i = 0; i < size-1; i++)
	{
		if (arr[i] < arr[i + 1])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	int arr[] = { -2, 3, 4 , 5, 6 };

	std::cout << isInDescendingOrder(arr, 5);
}