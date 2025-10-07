#include <iostream>

int biggestNumWithEvenIndex(const int arr[], const unsigned size) 
{
	if (arr == nullptr || size <= 0)
	{
		return -1;
	}

    int index = 0;
	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0 && arr[i] > arr[index])
		{
			index = i;
		}
	}

	return arr[index];
}

int main()
{
	int arr[] = { -2,-3,5,-3,2 , 6 };

	std::cout << biggestNumWithEvenIndex(arr, 6);
}