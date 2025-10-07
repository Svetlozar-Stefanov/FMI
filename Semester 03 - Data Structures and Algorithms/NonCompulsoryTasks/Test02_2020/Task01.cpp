#include <iostream>
#include <vector>

using namespace std;

void Task01() {
	int N;
	cin >> N;
	vector<int> arr(N);
	int counter[200000] = {0};
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		counter[arr[i]]++;
	}
	
	for (int i = 200000 - 1; i >= 1 ; i--)
	{
		counter[i] += counter[i - 1];
	}

	vector<int> cpy = arr;

	for (int i = N-1; i >= 0; i--)
	{
		arr[counter[cpy[i]] - 1] = cpy[i];
		counter[cpy[i]]--;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}