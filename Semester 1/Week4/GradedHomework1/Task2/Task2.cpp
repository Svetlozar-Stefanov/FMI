#include <iostream>

using namespace std;

bool hasFirstWinner = false;

int digitsNum(int number)
{
	int counter = 0;
	while (number > 0)
	{
		number /= 10;
		counter++;
	}

	return counter;
}
int pown(int num, int n) 
{
	int output = 1;
	for (int i = 0; i < n; i++)
	{
		output *= num;
	}

	return output;
}
void checkForFirstWinner() 
{
	if (!hasFirstWinner)
	{
		hasFirstWinner = true;
	}
	else
	{
		cout << " ";
	}
}

int main()
{
    unsigned int input;

	cin >> input;

	if (1 <= input && input <= INT_MAX)
	{
		int loopCount;
		int numberOfDigits = digitsNum(input);

		if (numberOfDigits % 2 == 0)
		{
			loopCount = numberOfDigits / 2;
		}
		else
		{
			loopCount = (numberOfDigits / 2) + 1;
		}

		
		for (int i = 0; i < loopCount; i++)
		{
			int leftDigit = (input % pown(10, numberOfDigits - i)) / pown(10, numberOfDigits - i - 1);
			int rightDigit = (input % pown(10, 1 + i)) / pown(10, i);

			if (leftDigit > rightDigit)
			{
				checkForFirstWinner();

				cout << leftDigit;
			}
			else if (leftDigit < rightDigit)
			{
				checkForFirstWinner();

				cout << rightDigit;
			}
			else if (loopCount % 2 != 0 && loopCount - 1 == i)
			{
				checkForFirstWinner();

				cout << rightDigit;
			}
		}
	}
}
