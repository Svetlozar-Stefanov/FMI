#include <iostream>

void ShuffleSort(int* arr, const int size) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	int * sortedArr = new int[size];
	int index = 0;
	for (int i = 0; i < size; i++)
	{
		sortedArr[i++] = arr[index];
		if (i < size )
		{
			sortedArr[i] = arr[size - index - 1];
		}
		index++;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] = sortedArr[i];
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,0 };
	int size = 6;
	ShuffleSort(arr, size);

	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}