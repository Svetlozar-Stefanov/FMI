#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int m = 0;

	cin >> n;
	cin >> m;

	int sum = 1;

	for (int i = 0; i < m; i++)
	{
		sum *= n + i;
	}

	cout << sum * m;
}
