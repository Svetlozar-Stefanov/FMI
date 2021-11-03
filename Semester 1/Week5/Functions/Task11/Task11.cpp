#include <iostream>
#include <string>

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

void getNumWithRepeatedDigits(const int from, const int to)
{
	for (int num = from; num <= to; num++)
	{
		int digits = 0;

		int temp = num;
		while (temp > 0)
		{
			temp /= 10;
			digits++;
		}


		bool foundMatch = false;
		for (int i = 0; i < digits; i++)
		{
			int currentMainDigit = (num % pow(10, i + 1)) / pow(10, i);

			for (int j = 0; j < digits; j++)
			{
				int currentDigit = (num % pow(10, j + 1)) / pow(10, j);

				if (currentMainDigit == currentDigit && i != j)
				{
					cout << num << endl;
					foundMatch = true;
					break;
				}
			}
			if (foundMatch)
			{
				break;
			}
		}
	}
}

int main()
{
	getNumWithRepeatedDigits(60, 120);
	
}
