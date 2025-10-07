#include <iostream>

void convertMax(int * arr, const int N) 
{
	if (arr == nullptr)
	{
		return;
	}

    int maxI = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[maxI] < arr[i])
		{
			maxI = i;
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (i != maxI)
		{
			arr[i] += arr[maxI];
		}
	}

	for (int i = 0; i < N/2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[N - i - 1];
		arr[N - i - 1] = temp;
	}
}

int main()
{
	int arr[] = { 11, 5, 2, 4, 8, 2 };
	convertMax(arr, 6);

	for (int i = 0; i < 6; i++)
	{
		std::cout << arr[i] << " ";
	}
}