#include <iostream>

bool isMember(const int arr[], const unsigned size, const int num) 
{
	if (arr == nullptr || size <= 0)
	{
		return false;
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == num)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	int arr[] = { -2, 3, 4 , 5, 6 };

	std::cout << isMember(arr, 5, 1);
}