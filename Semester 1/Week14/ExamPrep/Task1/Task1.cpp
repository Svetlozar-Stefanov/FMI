#include <iostream>

int largestSeq(const int arr[], const int N) 
{
	if (arr == nullptr)
	{
		return 0;
	}

	int start = 0;
	int end = 0;
	for (int i = 0; i < N; i++)
	{
		int index = i;
		while (arr[index] % 2 == 0)
		{
			index++;
		}

		if (index - i > end - start)
		{
			start = i;
			end = index;
		}

		if (index != i)
		{
			i = index - 1;
		}
	}

	int sum = 0;
	for (int i = start; i < end; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int main()
{
	int arr[] = { 2, 4, 3, 11, 12, 168, 144, 5, 9, 62, 98, 1 };
	std::cout << largestSeq(arr, 12);
}
