#include <iostream>

int findElement(long arr[], int I) 
{
	int max = -1;
	for (int i = 1; i < I-1; i++)
	{
		if (arr[i] > (arr[i-1] + arr[i+1]) / 2)
		{
			max = i;
		}
	}

	return max;
}

int main()
{
	long arr[] = { 2, 3, 17, 8, 1, 9 };

    std::cout << findElement(arr, 6);
}