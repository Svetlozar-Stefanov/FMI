#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		int sum = arr[i];
		int l = 0;
		int r = arr.size() - 1;

		while(l < r)
		{
			if (arr[l] + arr[r] > sum)
			{
				r--;
			}
			else if (arr[l] + arr[r] < sum) {
				l++;
			}
			else
			{
				cout << "true";
				return 0;
			}
		}
	}

	cout << "false";
	return 1;
}
