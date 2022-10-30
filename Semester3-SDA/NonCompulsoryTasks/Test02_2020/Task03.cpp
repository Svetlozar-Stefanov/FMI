#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

struct Pair {
	int index;
	int x;
	int y;
};

bool comp(Pair& p1, Pair& p2) {
	if (p1.x * p1.x * p2.y == p2.x * p2.x * p1.y)
	{
		return p1.x > p2.x;
	}
	return p1.x * p1.x * p2.y > p2.x* p2.x* p1.y;
}

void Task03() {
	int N;
	cin >> N;
	vector<Pair> pairs(N);
	for (int i = 0; i < N; i++)
	{
		pairs[i].index = i;
		cin >> pairs[i].x;
		cin >> pairs[i].y;
	}

	sort(pairs.begin(), pairs.end(), comp);

	for (int i = 0; i < N; i++)
	{
		cout << pairs[i].index + 1 << " ";
	}

}