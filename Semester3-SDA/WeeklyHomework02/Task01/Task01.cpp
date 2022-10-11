#include <iostream>
#include <vector>

using namespace std;

void redBlackSort(vector<int>& arr) {
	vector<int> cpy = arr;

	int top = 3;
	int* count = new int[top];
	for (int i = 0; i < top; i++)
	{
		count[i] = 0;
	}

	for (int i = 0; i < arr.size(); i++)
	{
		count[arr[i] % 2]++;
	}

	for (int i = 1; i < top - 1; i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[count[cpy[i] % 2] - 1] = cpy[i];
		count[cpy[i] % 2]--;
	}

	delete[] count;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
	}

	redBlackSort(nums);

	for (int i = 0; i < N; i++)
	{
		cout << nums[i] << '\n';
	}
}