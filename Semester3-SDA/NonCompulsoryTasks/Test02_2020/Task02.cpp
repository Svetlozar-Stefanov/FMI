#include <iostream>
#include <vector>

using namespace std;

void Task02() {
	int N;
	cin >> N;
	int counter[50000] = {0};
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		counter[n]++;
	}

	for (int i = 0; i < 50000; i++)
	{
		if (counter[i] == 0)
		{
			continue;
		}
		cout << i << " ";
	}
}