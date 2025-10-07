#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Interval
{
	int s;
	int e;
};

bool operator<(Interval& i1, Interval& i2)
{
	return i1.s >= i2.s && i1.s <= i2.e && i1.e <= i2.e && i1.e >= i2.s;
}

bool check(Interval& i1, Interval& i2) {
	if (i1.s >= i2.s && i1.s <= i2.e && i1.e <= i2.e && i1.e >= i2.s)
	{
		return true;
	}
	else if (i1.e < i2.s || i1.e < i2.e)
	{
		return true;
	}
	return false;
}

int main()
{
	int N;
	cin >> N;
	vector<Interval> intervals(N);
	for (int i = 0; i < N; i++)
	{
		cin >> intervals[i].s;
		cin >> intervals[i].e;
	}

	sort(intervals.rbegin(), intervals.rend(), check);

	for (int i = 0; i < N; i++)
	{
		cout << intervals[i].s << " " << intervals[i].e << '\n';
	}

	int count = 0;
	Interval current;
	if (N > 0)
	{
		current = intervals[0];
	}
	for (int i = 1; i < N; i++)
	{
		if (intervals[i] < current)
		{
			count++;
		}
		else
		{
			current = intervals[i];
		}
	}
	cout << count;
}
