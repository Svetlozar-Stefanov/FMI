#include <iostream>
#include <vector>

using namespace std;

int count(vector<int> &arr, int l, int m, int r) {
	int counter = 0;
	for (int j = m + 1; j <= r; j++)
	{
		for (int i = l; i <= m; i++)
		{
			if (arr[j] < arr[i])
			{
				counter++;
			}
		}
	}

	return counter;
}

int inversionCounterHelper(vector<int> &arr, int l, int r) {
	if (l >= r)
	{
		return 0;
	}

	int m = l + (r - l) / 2;

	int counter = 0;
	counter += inversionCounterHelper(arr, l, m);
	counter += inversionCounterHelper(arr, m + 1, r);

	return counter + count(arr, l, m, r);
}

int inversionCounter(vector<int> arr) {
	return inversionCounterHelper(arr, 0, arr.size() - 1);
}

int main()
{
	//vector<int> arr = { 5, -3, 4, -5, 2, 1, -4, 0, 3, -2, -1 };
	//vector<int> arr = { 132, 312, 52342, 5436, 3543, 3234, 6234, 745, 3123 };
	vector<int> arr = { 3, 2, 1, 0 };

	cout << inversionCounter(arr);
}
