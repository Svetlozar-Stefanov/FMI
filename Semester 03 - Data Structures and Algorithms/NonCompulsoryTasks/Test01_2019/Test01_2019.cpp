#include <iostream>
#include <vector>

using namespace std;

void countingSort(vector<int> &arr) {
	int count[100000] = {0};

	for (int i = 0; i < arr.size(); i++)
	{
		count[arr[i]]++;
	}

	for (int i = 1; i < 100000; i++)
	{
		count[i] += count[i - 1];
	}

	vector<int> cpy = arr;

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[arr.size() - count[cpy[i]]] = cpy[i];
		count[cpy[i]]--;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	uint64_t N;
	cin >> N;
	vector<int> arr(N);
	for (uint64_t i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	countingSort(arr);

	for (uint64_t i = 0; i < N; i++)
	{
		printf("%d ", arr[i]);
	}
}
