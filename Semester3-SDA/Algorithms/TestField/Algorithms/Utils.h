#pragma once
#include <vector>

using namespace std;

void swap(vector<int>& arr, int i1, int i2)
{
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

int max(vector<int> &arr) {
	int max = INT_MIN;
	for (int i = 0; i < arr.size(); i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}