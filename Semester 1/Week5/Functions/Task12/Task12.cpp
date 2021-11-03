#include <iostream>

using namespace std;

int pow(const int a, const int n)
{
	int output = 1;

	for (int i = 0; i < n; i++)
	{
		output *= a;
	}

	return output;
}

int getDigitCount(const int number) 
{
	int digits = 0;

	int temp = number;
	while (temp > 0)
	{
		temp /= 10;
		digits++;
	}

	return digits;
}

double getDigitAvg(const int number) 
{
	int digits = getDigitCount(number);

	int sum = 0;
	for (int i = 0; i < digits; i++)
	{
		sum += (number % pow(10, i + 1)) / pow(10, i);
	}

	return (double)sum / digits;
}

int main()
{
	int m;
	int n;
	int k;

	cin >> m;
	cin >> n;
	cin >> k;

	for (int num = m; num <= n; num++)
	{
		if (getDigitAvg(num) >= k)
		{
			cout << num << endl;
		}
	}
}
