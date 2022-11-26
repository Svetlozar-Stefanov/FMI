#include <iostream>
#include <set>

using namespace std;

int main()
{
    int N;
    cin >> N;

	set<int> goodMasks;

	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		goodMasks.insert(a);
		for (int i = a - 1; i >= 0; i--)
		{
			if ((~a & ~i) == ~a)
			{
				goodMasks.insert(i);
			}
		}
	}

	cout << goodMasks.size();
}
