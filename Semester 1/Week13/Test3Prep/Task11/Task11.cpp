#include <iostream>

void reverseSigns(int arr[], const unsigned size) 
{
	if (arr == nullptr || size <= 0)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		arr[i] *= -1;
	}
}

int main()
{
	int arr[] = { -2, 3, 5 , 2, 6 };

	reverseSigns(arr, 5);

	for (int i = 0; i < 5; i++)
	{
		std::cout << arr[i] << " ";
	}
}