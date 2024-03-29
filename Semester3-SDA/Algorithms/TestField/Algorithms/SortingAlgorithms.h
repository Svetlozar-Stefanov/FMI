#pragma once
#include <vector>
#include "Utils.h"

using namespace std;

//Insertion Sort
void insertionSort(vector<int> &arr) {
	int size = arr.size();

	for (int i = 1; i < size; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			swap(arr, j, j+1);
			j--;
		}
		arr[j+1] = key;
	}
}

//Merge Sort
void special_merge(vector<int>& arr, int l, int m, int r) {
	vector<int> A;
	for (int i = l; i <= m; i++)
	{
		A.push_back(arr[i]);
	}
	A.push_back(INT_MAX);

	vector<int> B;
	for (int i = m + 1; i <= r; i++)
	{
		B.push_back(arr[i]);
	}
	B.push_back(INT_MAX);

	uint64_t iA = 0;
	uint64_t iB = 0;
	uint64_t i = l;

	for (int i = 0; i < r-l+1; i++)
	{
		if (A[iA] <= B[iB])
		{
			arr[i++] = A[iA++];
		}
		else
		{
			arr[i++] = B[iB++];
		}
	}
}

void merge(vector<int>& arr, int l, int m, int r) {
	vector<int> A;
	for (int i = l; i <= m; i++)
	{
		A.push_back(arr[i]);
	}

	vector<int> B;
	for (int i = m + 1; i <= r; i++)
	{
		B.push_back(arr[i]);
	}

	uint64_t iA = 0;
	uint64_t iB = 0;
	uint64_t i = l;

	while (iA < A.size() && iB < B.size())
	{
		if (A[iA] <= B[iB])
		{
			arr[i++] = A[iA++];
		}
		else
		{
			arr[i++] = B[iB++];
		}
	}

	while (iA < A.size())
	{
		arr[i++] = A[iA++];
	}

	while (iB < B.size())
	{
		arr[i++] = B[iB++];
	}
}

void mergeSortHelper(vector<int>& arr, int l, int r) {
	if (l >= r)
	{
		return;
	}

	int m = l + (r - l) / 2;

	mergeSortHelper(arr, l, m);
	mergeSortHelper(arr, m + 1, r);

	merge(arr, l, m, r);
}

void mergeSort(vector<int> &arr) {
	mergeSortHelper(arr, 0, arr.size() - 1);
}

//Quicksort

int partition(vector<int>& arr, int l, int r) 
{
	int pivot = arr[r];

	int s = l;
	for (int i = l; i < r; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr, s, i);
			s++;
		}
	}
	swap(arr, s, r);

	return s;
}

int randomized_partition(vector<int>& arr, int l, int r)
{
	srand(NULL);
	int pI = rand() % (r - l) + l;
	swap(arr, pI, r);
	return partition(arr, l, r);
}

void quicksortHelper(vector<int> &arr, int l, int r) {
	if (l >= r)
	{
		return;
	}

	int m = randomized_partition(arr, l, r);

	quicksortHelper(arr, l , m-1);
	quicksortHelper(arr, m + 1, r);
}

void quicksort(vector<int> &arr) {
	quicksortHelper(arr, 0, arr.size() - 1);
}

//Counting Sort
void countingSort(vector<int>& arr) {
	vector<int> cpy = arr;

	int top = max(arr) + 1;
	int* count = new int[top];
	for (int i = 0; i < top; i++)
	{
		count[i] = 0;
	}

	for (uint64_t i = 0; i < arr.size(); i++)
	{
		count[arr[i]]++;
	}

	for (int i = 1; i < top; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[count[cpy[i]] - 1] = cpy[i];
		count[cpy[i]]--;
	}

	delete[] count;
}

//Radix Sort
void radixHelper(vector<int>& arr, int place) {
	vector<int> cpy = arr;
	int top = 10;
	int* count = new int[top];
	for (int i = 0; i < top; i++)
	{
		count[i] = 0;
	}

	for (uint64_t i = 0; i < arr.size(); i++)
	{
		count[(arr[i] / place) % 10]++;
	}

	for (int i = 1; i < top - 1; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[count[(cpy[i] / place) % 10 ] - 1] = cpy[i];
		count[(cpy[i] / place) % 10]--;
	}

	delete[] count;
}

void radixSort(vector<int> &arr) {
	int maxEl = max(arr);

	for (int place = 1; maxEl / place > 0; place *= 10)
	{
		radixHelper(arr, place);
	}
}