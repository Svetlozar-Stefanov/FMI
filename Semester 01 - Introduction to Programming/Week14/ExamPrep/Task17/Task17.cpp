#include <iostream>

void convertArr(long arr[], long S, long E)
{
	if (S < 0 || S >= E)
	{
		return;
	}

	int size = E - S + 1;
	for (int i = 0; i < size / 2; i++)
	{
		int temp = arr[i + S];
		arr[i + S] = arr[E - i];
		arr[E-i] = temp;
	}
}

int main()
{
	long arr[] = { 4, 5, 6, 7, 8, 9, 0, 1 };
	convertArr(arr, 1, 5);

	for (int i = 0; i < 8; i++)
	{
		std::cout << arr[i] << " ";
	}
}