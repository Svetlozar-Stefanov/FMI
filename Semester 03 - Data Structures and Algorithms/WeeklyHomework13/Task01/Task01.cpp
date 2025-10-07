#include <iostream>
#include <vector>

using namespace std;

const int TIME_LEFT = 10080;

int main()
{
    int N;
    cin >> N;
	vector<int> lists(N);
	for (int i = 0; i < N; i++)
	{
		cin >> lists[i];
	}

	vector<vector<int>> table(N+1);
	for (int i = 0; i < N+1; i++)
	{
		vector<int> temp(TIME_LEFT+1);
		table[i] = temp;
	}

	for (int i = 0; i < N + 1; i++)
	{
		table[i][0] = 1;
	}

	for (int n = 1; n < N+1; n++)
	{
		for (int t = 1; t < TIME_LEFT+1; t++)
		{
			if (lists[n-1] > t)
			{
				table[n][t] = table[n - 1][t];
			}
			else
			{
				table[n][t] = (table[n - 1][t] + table[n - 1][t - lists[n - 1]]);
			}
		}
	}
	int count = 0;
	for (int i = 1; i < TIME_LEFT+1; i++)
	{
		count = (count + table[N][i]) % 1000000007;
	}
	cout << count;
}