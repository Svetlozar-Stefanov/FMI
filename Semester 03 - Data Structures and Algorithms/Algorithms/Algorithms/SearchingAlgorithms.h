#pragma once
#include <vector>

using namespace std;

bool linearSearch(vector<int>& arr, int x) {
	int size = arr.size();
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			return true;
		}
	}

	return false;
}

bool binarySearch(vector<int>& arr, int x, int l, int r) {
	if (l > r)
	{
		return false;
	}

	int m = (r + l) / 2;
	if (x > arr[m])
	{
		return binarySearch(arr, x, m + 1, r);
	}
	else if (x < arr[m])
	{
		return binarySearch(arr, x, l, m - 1);
	}

	return true;
}

bool ternarySearch(vector<int>& arr, int x, int l, int r)
{
	if (l > r)
	{
		return false;
	}

	int m1 = (2 * l + r) / 3;
	int m2 = (l + 2 * r) / 3;

	if (x < arr[m1])
	{
		return ternarySearch(arr, x, l, m1-1);
	}
	else if (x > arr[m1] && x < arr[m2])
	{
		return ternarySearch(arr, x, m1 + 1, m2 - 1);
	}
	else if (x > arr[m2])
	{
		return ternarySearch(arr, x, m1 + 1, r);
	}

	return true;
}

int jumpSearch(vector<int>& arr, int x) {
	int n = arr.size();

	int step = sqrt(n);
	int increment = step;
	int prev = 0;
	while (arr[min(step, n) - 1] < x)
	{
		prev = step;
		step += increment;
		if (prev >= n)
		{
			return -1;
		}
	}

	while (arr[prev] < x)
	{
		prev++;
		if (prev == min(step, n))
		{
			return -1;
		}
	}

	if (arr[prev] == x)
	{
		return	prev;
	}

	return -1;
}

int rand_partition(vector<int>& arr, int n, int l, int r) {
	int pI = rand() % (r - l) + l;
	swap(arr, pI, r);
	
	int s = l;
	for (int i = l; i < r; i++)
	{
		if (arr[i] > arr[r])
		{
			swap(arr, i, s);
			s++;
		}
	}
	swap(arr, s, r);
	return s;
}

int quickselectNthNumHelper(vector<int>& arr, int n, int l, int r) 
{
	if (l >= r)
	{
		if (l == r && r == n)
		{
			return arr[n];
		}
		return -1;
	}

	int m = rand_partition(arr, n, l, r);

	if (n > m)
	{
		return quickselectNthNumHelper(arr, n, m + 1, r);
	}
	else if (n < m)
	{
		return quickselectNthNumHelper(arr, n, l, m - 1);
	}

	return arr[m];
}

int quickselectNthNum(vector<int>& arr, int n)
{
	return quickselectNthNumHelper(arr, n-1, 0, arr.size()-1);
}

int upper_bound(vector<int>& arr, int l, int r, int x)
{
	if (r - l <= 1)
	{
		if (arr[l] == x)
		{
			return l;
		}
		return r;
	}

	int m = l + (r - l) / 2;

	if (arr[m] > x)
	{
		return upper_bound(arr, l, m, x);
	}
	else if (arr[m] <= x) {
		return upper_bound(arr, m+1, r, x);
	}
}

int longestIncreasingSubsequence(vector<int> &arr) 
{
	if (arr.size() <= 0)
	{
		return -1;
	}

	vector<int> ends;
	ends.push_back(arr[0]);

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] < ends[0])
		{
			ends[0] = arr[i];
		}
		else if (arr[i] > ends[ends.size()-1])
		{
			ends.push_back(arr[i]);
		}
		else
		{
			int idx = upper_bound(ends, 0, ends.size() - 1, arr[i]);
			ends[idx] = arr[i];
		}
	}

	return ends.size();
}