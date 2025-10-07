#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
	int s;
	int e;
};

bool isSmaller(Interval& i1, Interval& i2) {
	if (i1.s == i2.s)
	{
		return i1.e < i2.e;
	}

	return i1.s < i2.s;
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

	sort(intervals.begin(), intervals.end(), isSmaller);

	Interval start = intervals[0];
	Interval end = intervals[0];

	for (int i = 1; i < N; i++)
	{
		if ((start.s <= intervals[i].s && intervals[i].s <= end.e)
			&& intervals[i].e >= end.e)
		{
			end = intervals[i];
			continue;
		}

		if (intervals[i].e <= end.e && intervals[i].s >= start.s)
		{
			continue;
		}

		cout << start.s << " " << end.e << '\n';
		start = intervals[i];
		end = intervals[i];
		
	}
	cout << start.s << " " << end.e << '\n';
}
