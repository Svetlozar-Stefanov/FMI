#include <iostream>

bool hasTwoEqualAdjMembers(const int arr[], const unsigned size) 
{
	if (arr == nullptr || size <= 0)
	{
		return false;
	}

	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int arr[] = { -2, 3, 4 , 2, 6 };

	std::cout << hasTwoEqualAdjMembers(arr, 5);
}
