#pragma once
#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& arr, int l, int r, int x, int &c)
{
	if (l > r)
	{
		--c;
		return -1;
	}

	int m = l + (r - l) / 2;
	if (x < arr[m])
	{
		return search(arr, l, m-1, x, ++c);
	}
	else if (x > arr[m])
	{
		return search(arr, m + 1, r, x, ++c);
	}

	return m;
}

void Task02() {
	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	int K;
	cin >> K;
	vector<pair<int, int>> q(K);
	for (int i = 0; i < K; i++)
	{
		int x;
		cin >> x;

		int c = 1;
		int idx = search(arr, 0, arr.size()-1, x, c);
		q[i].first = idx;
		q[i].second = c;
	}

	for (int i = 0; i < K; i++)
	{
		cout << q[i].first << " ";
	}
	cout << '\n';
	for (int i = 0; i < K; i++)
	{
		cout << q[i].second << " ";
	}
}