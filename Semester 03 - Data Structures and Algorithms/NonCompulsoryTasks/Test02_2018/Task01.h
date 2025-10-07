#pragma once
#include <iostream>
#include <vector>

using namespace std;

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

	int a = 0;
	int b = 0;
	int k = l;

	while (a < A.size() && b < B.size())
	{
		if (A[a] <= B[b])
		{
			arr[k++] = A[a++];
		}
		else if (A[a] > B[b])
		{
			arr[k++] = B[b++];
		}
	}

	while (a < A.size())
	{
		arr[k++] = A[a++];
	}

	while (b < B.size())
	{
		arr[k++] = B[b++];
	}

	for (int i = l; i <= r; i++)
	{
		cout << arr[i] << " ";
	}
}

void sort(vector<int> &arr, int l, int r) {
	if (l >= r)
	{
		cout << arr[l] << " ";
		return;
	}

	int m = l + (r - l) / 2;
	sort(arr, l, m);
	sort(arr, m + 1, r);

	merge(arr, l, m, r);
}

void Task01(){
	int N;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, 0, arr.size()-1);
}