#include <iostream>

int* mergeArrays(const int arr1[],const int arr2[],const int m)
{
	if (arr1 == nullptr || arr2 == nullptr)
	{
		return nullptr;
	}

	int* arr = new int[m];

	for (int i = 0; i < m; i++)
	{
		arr[i] = arr1[i] + arr2[m - i - 1];
	}

	return arr;
}

int main()
{
	int arr1[] = { 1, 2, 3, 4 };
	int arr2[] = { 2, 5, 7, 11 };

	int* arr = mergeArrays(arr1, arr2, 4);

	for (int i = 0; i < 4; i++)
	{
		std::cout << arr[i] << " ";
	}
}