#include <iostream>

using namespace std;

int main()
{
	int smallerNumber = INT_MAX;
	int input = 0;
	int counter = 0;

	while (counter < 3)
	{
		cin >> input;
		if (input < 0)
		{
			counter++;
		}
		else
		{
			counter = 0;
		}

		if (smallerNumber > input)
		{
			smallerNumber = input;
		}
		
	}

	cout << smallerNumber;
}
