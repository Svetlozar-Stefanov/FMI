#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	stack<int> lToR;
	queue<int> rToL;
	
	for (int i = 0; i < N; i++)
	{
		int n = arr[i];

		if (n < 0 && lToR.empty())
		{
			cout << n << " ";
		}
		else if (n > 0 && rToL.empty())
		{
			lToR.push(n);
		}
		else if (n < 0 && !lToR.empty())
		{
			while (i < N && arr[i] < 0)
			{
				rToL.push(arr[i++]);
			}
			i--;

			while (!lToR.empty() && !rToL.empty())
			{
				int l = lToR.top();
				int r = rToL.front();
				if (abs(r) < l)
				{
					rToL.pop();
				}
				else if (abs(r) > l)
				{
					lToR.pop();
				}
				else
				{
					rToL.pop();
					lToR.pop();
				}
			}

			while (!rToL.empty())
			{
				cout << rToL.front() << " ";
				rToL.pop();
			}
		}
	}

	vector<int> temp;
	while (!lToR.empty())
	{
		temp.push_back(lToR.top());
		lToR.pop();
	}
	for (int j = temp.size() - 1; j >= 0; j--)
	{
		cout << temp[j] << " ";
	}
}
