#include <iostream>

using namespace std;

int main()
{
	int sum1 = 0;

	for (int i = 1; i <= 100; i++)
	{
		sum1 += i;
	}

	int m;
	cin >> m;
	int n;
	cin >> n;

	int sum2 = 0;

	for (int i = 0; i <= n; i++)
	{
		sum2 += m + i;
	}

	double sum3 = 0;

	for (double i = 1; i <= 10; i++)
	{
		sum3 += 1 / i;
	}

	cout << sum1 << "\n";
	cout << sum2 << "\n";
	cout << sum3;
	
}
