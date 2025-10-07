#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << fixed << setprecision(1);

	priority_queue<uint64_t> left;
	priority_queue<uint64_t, vector<uint64_t>, greater<uint64_t>> right;

    int N;
    cin >> N;
	for (int i = 0; i < N; i++)
	{
		uint64_t n;
		cin >> n;

		if (right.empty() || n >= right.top())
		{
			right.push(n);
		}
		else if (left.empty() || n <= left.top())
		{
			left.push(n);
		}
		else if (!right.empty() && !left.empty() && left.top() < n && n < right.top())
		{
			right.push(n);
		}

		int lS = left.size();
		int rS = right.size();

		if ((lS - rS) > 1)
		{
			right.push(left.top());
			left.pop();
		}
		else if ((rS - lS) > 1)
		{
			left.push(right.top());
			right.pop();
		}

		if (left.size() > right.size())
		{
			cout << (double)left.top() << '\n';
		}
		else if (left.size() < right.size())
		{
			cout << (double)right.top() << '\n';
		}
		else
		{
			double med = (double)left.top() + (double)right.top();
			double res = med / 2;
			cout << res << '\n';
		}
	}
}
