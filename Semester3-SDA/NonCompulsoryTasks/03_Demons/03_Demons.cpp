#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Demon {
	int64_t attack;
	int64_t deffence;
};

bool bigger(Demon& d1, Demon& d2)
{
	return d1.attack > d2.attack && d1.deffence > d2.deffence;
}

bool smaller(Demon& d1, Demon& d2)
{
	return d1.attack < d2.attack && d1.deffence < d2.deffence;
}


int upper_bound(vector<Demon>& demons, int l, int r, Demon x)
{
	if (r - l <= 1)
	{
		return r;
	}

	int m = l + (r - l) / 2;
	
	if (bigger(demons[m], x))
	{
		return upper_bound(demons, m, r, x);
	}
	else 
	{
		return upper_bound(demons, r, m, x);
	}
}

int maxDemonsSlain(vector<Demon> &demons) 
{
	if (demons.size() <= 0)
	{
		return 0;
	}

	vector<Demon> ends;
	ends.push_back(demons[0]);

	for (int i = 1; i < demons.size(); i++)
	{
		if (bigger(demons[i], ends[0]))
		{
			ends[0] = demons[i];
		}
		else if (bigger(ends[ends.size() - 1], demons[i]))
		{
			ends.push_back(demons[i]);
		}
		else
		{
			ends[upper_bound(ends, 0, ends.size() - 1, demons[i])] = demons[i];
		}
	}

	return ends.size();
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<Demon> demons(N);
	for (int i = 0; i < N; i++)
	{
		cin >> demons[i].attack;
		cin >> demons[i].deffence;
	}

	sort(demons.begin(), demons.end(), [](const Demon& first, const Demon& second) -> bool {
		return first.attack > second.attack || (first.attack == second.attack && first.deffence > second.deffence); });

	cout << maxDemonsSlain(demons);
}
