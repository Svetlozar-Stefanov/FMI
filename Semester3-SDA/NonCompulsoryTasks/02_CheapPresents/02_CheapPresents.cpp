#include <iostream>

using namespace std;

int prices[1000000];

void swap(int * arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int * arr, int l, int r) {
	int pivot = arr[r];

	int index = l;
	for (int i = l; i < r; i++) 
	{
		if(arr[i] <= pivot) {
			swap(arr, index, i);

			index++;
		}
	}
	swap(arr, index, r);

	return index;
}

void quicksortHelper(int* arr, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int part = partition(arr, l, r);

	quicksortHelper(arr, l, part-1);
	quicksortHelper(arr, part + 1, r);
}

void quicksort(int * arr, int size) {
	quicksortHelper(arr, 0, size-1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	int K = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> prices[i];
	}
	cin >> K;

	quicksort(prices, N);

	long long minimalSum = 0;
	for (int i = 0; i < K; i++)
	{
		minimalSum += prices[i];
	}

	cout << minimalSum;
}
