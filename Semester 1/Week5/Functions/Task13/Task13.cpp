#include <iostream>

using namespace std;

int numberOfKIn(int n, const int k) 
{
	int temp = abs(n);

	int counter = 0;

	while (temp > 0)
	{
		int currentDigit = temp % 10;

		if (currentDigit == k)
		{
			counter++;
		}

		temp /= 10;
	}

	return counter;
}

int main()
{
	int k;
	int input;
	int counter = 0; 

	cin >> k;

	do
	{
		cin >> input;

		if (numberOfKIn(input, k) >= 2)
		{
			counter++;
		}

	} while (input > 0);

	cout << counter;
}
