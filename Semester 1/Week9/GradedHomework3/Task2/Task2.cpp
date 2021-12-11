#include <iostream>

using namespace std;

int longestDist(const int arr[], const int arrSize) 
{
	int maxDist = INT_MIN;
	int index = -1;

	for (int i = 0; i < arrSize; i++)
	{
		int current = arr[i];
		for (int j = arrSize - 1; j > i; j--)
		{
			if (current == arr[j] 
				&& maxDist < j - i)
			{
				maxDist = j - i;
				index = i;
			}
		}
	}

	return index;
}

int main()
{
	int N;
	int arr[100];

	if (!(cin >> N) || 
		N <= 1 || N > 100)
	{
		cout << "-2";
		return 1;
	}

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cout << longestDist(arr, N);
}
