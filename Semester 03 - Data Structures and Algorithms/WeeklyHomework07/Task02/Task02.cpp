#include <iostream>
#include <climits>
#include <queue>
#include <set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set<int> searchSet;

    int Q;
    cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		queue<int> candies;
		int max = INT_MIN;
		int N;
		cin >> N;
		for (int j = 0; j < N; j++)
		{
			int c;
			cin >> c;
			if (!searchSet.count(c))
			{
				candies.push(c);
				searchSet.insert(c);
				int size = candies.size();
				if (max < size)
				{
					max = size;
				}
			}
			else
			{
				while (candies.front() != c)
				{
					searchSet.erase(candies.front());
					candies.pop();
				}
				searchSet.erase(candies.front());
				candies.pop();

				candies.push(c);
				searchSet.insert(c);
			}
		}
		searchSet.clear();

		cout << max << '\n';
	}
}
