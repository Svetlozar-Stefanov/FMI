// Svetlozar Stefanov 4MI0600030

#include <iostream>
#include <climits>

using namespace std;

long long second(int arr[], const int size) 
{
	// First we sort the array
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

	//And then we find the second largest element
	int secondMax = arr[size - 1];
	for (int i = size - 1; i >= 0; i--)
	{
		if (arr[i] < secondMax)
		{
			secondMax = arr[i];
			return secondMax;
		}
	}
	
	//If there is not one we return a value outside of int
	if (secondMax == arr[size - 1])
	{
		return LLONG_MAX;
	}
}

int main()
{
	int size = 5;
	int arr[50] = {1, 2, 3, 5, 5};

	cout << second(arr, size);
}
