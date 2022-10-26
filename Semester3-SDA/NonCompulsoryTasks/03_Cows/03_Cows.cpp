#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check(vector<int>& arr, int candidate, int cows) {
	int start = arr[0];
	int elCount = 1;

	for (int i = 1; i < arr.size(); i++)
	{
		if (arr[i] - start >= candidate)
		{
			start = arr[i];
			elCount++;

			if (elCount == cows)
			{
				return true;
			}
		}
	}
	return false;
}

int findMinMaxDistance(vector<int>& arr, int lR, int hR, int cows)
{
	if (lR >= hR)
	{
		return lR;
	}

	int mid = lR + (hR - lR) / 2;
	if (check(arr, mid, cows))
	{
		return findMinMaxDistance(arr, mid+1, hR, cows);
	}
	return findMinMaxDistance(arr, lR, mid, cows);
}

int main()
{
    int N, C;
    cin >> N >> C;
	vector<int> houses(N);
	
	for (int i = 0; i < N; i++)
	{
		cin >> houses[i];
	}
	sort(houses.begin(), houses.end());

	cout << findMinMaxDistance(houses, 1, houses[N-1] - 1, C);
}