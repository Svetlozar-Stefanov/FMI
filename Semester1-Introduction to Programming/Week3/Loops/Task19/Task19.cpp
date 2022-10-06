#include <iostream>

using namespace std;

int main()
{
	int sum = 0;
	int input = 0;
	int counter = 0;

	while (counter < 3)
	{
		cin >> input;
		if (input > 0)
		{
			counter++;
		}
		else
		{
			counter = 0;
		}

		sum += input;
	}

	cout << sum;
}
