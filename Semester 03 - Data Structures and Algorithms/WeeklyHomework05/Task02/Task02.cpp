#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int findMin(queue<int> &q) 
{
	int min = INT_MAX;
	for (int i = 0; i < q.size(); i++)
	{
		int n = q.front();
		q.pop();
		if (n < min)
		{
			min = n;
		}
		q.push(n);
	}

	return min;
}

int main()
{
    int N, k;
    cin >> N >> k;

	if (k == 0 || N == 0)
	{
		cout << 0;
		return 0;
	}

	queue<int> subarr;

	int currMin = INT_MAX;
	for (int i = 0; i < k; i++)
	{
		int n;
		cin >> n;
		subarr.push(n);
		if (n < currMin)
		{
			currMin = n;
		}
	}
	int64_t sum = currMin;

	for (int i = k; i < N; i++)
	{
		int n;
		cin >> n;

		int front = subarr.front();
		subarr.pop();
		subarr.push(n);
		
		if (n < currMin)
		{
			currMin = n;
		}
		else if(front == currMin)
		{
			currMin = findMin(subarr);
		}

		sum += currMin;
	}

	cout << sum;
	return 0;
}