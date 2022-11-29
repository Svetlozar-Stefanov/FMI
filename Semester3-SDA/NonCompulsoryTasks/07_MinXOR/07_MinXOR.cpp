#include <iostream>
#include <climits>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	set<int> numbers;
	numbers.insert(0);

    int Q;
    cin >> Q;

	int min = INT_MAX;

	for (int i = 0; i < Q; i++)
	{
		int n;
		cin >> n;
		numbers.insert(n);
		if (numbers.size() <= 2)
		{
			min = 0 ^ n;
		}	
		else
		{
			auto iter = numbers.find(n);
			int ln = *--iter;
			if ((n ^ ln) < min)
			{
				min = n ^ ln;
			}

			iter++;
			int rn = -1;
			if (++iter != numbers.end())
			{
				rn = *iter;
			}

			if (rn != -1 && (n ^ rn) < min)
			{
				min = n ^ rn;
			}
		}

		cout << min << "\n";
	}
}
