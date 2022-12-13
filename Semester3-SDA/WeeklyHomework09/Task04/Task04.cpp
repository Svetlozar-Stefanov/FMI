#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	
	cin >> N >> M;

	vector<int> nums(N);
	unordered_map<int, vector<int>> indices;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		indices[nums[i]].push_back(i);
	}

	int64_t count = 0;
	for (int i = 0; i < N; i++)
	{
		if (nums[i] % M != 0)
		{
			continue;
		}
		int l = nums[i] / M;
		int r = nums[i] * M;

		int ltemp = lower_bound(indices[l].begin(), indices[l].end(), i) - indices[l].begin();

		int rtemp = indices[r].size() - 
			(upper_bound(indices[r].begin(), indices[r].end(), i) - indices[r].begin());

		count += ltemp * rtemp;
	}

	cout << count;
}
