#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <set>

using namespace std;

uint64_t hour = 0;

struct Order
{
	int index;

	uint64_t beg;
	uint64_t dur;

	Order(int index, uint64_t beg, uint64_t dur)
	{
		this->index = index;
		this->beg = beg;
		this->dur = dur;
	}
};

struct sortComparator {
	bool operator()(Order const& a, Order const& b) const {
		return a.beg < b.beg || (a.beg == b.beg && a.dur < b.dur);
	}
};

struct orderComparator {
	bool operator()(Order const& a, Order const& b) const {
		bool c1 = a.beg <= hour;
		bool c2 = a.dur > b.dur;
		bool c4 = a.dur == b.dur;
		bool c5 = a.index > b.index;

		if (c1 && (c2 || (c4 && c5)))
		{
			return true;
		}
		return false;
	}
};

int main()
{
	int N;
	cin >> N;
	set<Order, sortComparator> orders;
	for (int i = 0; i < N; i++)
	{
		uint64_t beg, dur;
		cin >> beg;
		cin >> dur;
		orders.insert(Order(i, beg, dur));
	}

	priority_queue<Order, vector<Order>, orderComparator> pendingOrders;
	while (!orders.empty() || !pendingOrders.empty())
	{
		while (!orders.empty() && orders.begin()->beg <= hour)
		{
			Order temp = *orders.begin();
			pendingOrders.push(temp);
			orders.erase(temp);
		}

		if (!pendingOrders.empty())
		{
			cout << pendingOrders.top().index << " ";
			hour += pendingOrders.top().dur;
			pendingOrders.pop();
		}
		else if(!orders.empty())
		{
			Order temp = *orders.begin();
			cout << temp.index << " ";
			hour = temp.beg + temp.dur;
			orders.erase(temp);
		}
	}
}
