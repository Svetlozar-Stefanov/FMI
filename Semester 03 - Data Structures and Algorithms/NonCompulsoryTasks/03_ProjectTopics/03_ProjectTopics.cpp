#include <iostream>
#include <vector>

using namespace std;

void swap(int64_t* arr, int i1, int i2)
{
	int64_t temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

//int partition(int64_t* arr, int l, int r)
//{
//	int64_t pivot = arr[r];
//
//	int s = l;
//	for (int i = l; i < r; i++)
//	{
//		if (arr[i] <= pivot)
//		{
//			swap(arr, s, i);
//			s++;
//		}
//	}
//	swap(arr, s, r);
//
//	return s;
//}
//
//void quicksortHelper(int64_t* arr, int l, int r) {
//	if (l >= r)
//	{
//		return;
//	}
//
//	int m = partition(arr, l, r);
//
//	quicksortHelper(arr, l, m - 1);
//	quicksortHelper(arr, m + 1, r);
//}
//
//void quicksort(int64_t* arr, int size) {
//	quicksortHelper(arr, 0, size - 1);
//}

void insertionSort(int64_t * arr, int size) {
	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			swap(arr, j, j + 1);
			j--;
		}
		arr[j + 1] = key;
	}
}


int64_t closestComplexity(int64_t * complexity, int64_t knlg, int l, int r) {
	if (r - l <= 1)
	{
		int64_t c1 = abs(complexity[r] - knlg);
		int64_t c2 = abs(complexity[l] - knlg);
		if (c2 > c1)
		{
			return complexity[r];
		}

		return complexity[l];
	}

	int middle = l + (r - l) / 2;
	if (complexity[middle] > knlg)
	{
		return closestComplexity(complexity, knlg, l, middle);
	}
	else if (complexity[middle] < knlg)
	{
		return closestComplexity(complexity, knlg, middle, r);
	}

	return complexity[middle];
}

int64_t complexity[100001];
int64_t knowledge[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int M;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> complexity[i];
	}
	for (int i = 0; i < M; i++)
	{
		cin >> knowledge[i];
	}

	insertionSort(complexity, N);

	for (int i = 0; i < M; i++)
	{
		cout << closestComplexity(complexity, knowledge[i], 0, N-1) << "\n";
	}
}