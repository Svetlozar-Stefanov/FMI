#include <iostream>

int biggestNum(const int arr[], const unsigned size)
{
	if (arr == nullptr)
	{
		return -1;
	}

    int max = INT_MIN;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
	}

	return max;
}

int main()
{
	int arr[] = {1,2,3,5,3,2};

	std::cout << biggestNum(arr, 6);
}