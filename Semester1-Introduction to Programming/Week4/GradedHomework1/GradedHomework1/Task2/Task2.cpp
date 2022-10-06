/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 2
* @compiler VC
*
*/


#include <iostream>

using namespace std;

bool hasFirstWinner = false;

int digitsCount(int number)
{
	int counter = 0;
	while (number > 0)
	{
		number /= 10;
		counter++;
	}

	return counter;
}
int power(const int num, const int n)
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
	double input;

	if (!(cin >> input)
		|| !(1 <= input && input <= power(10, 9))
		|| input - (int)input != 0)
	{
		cout << "-1";
		return 1;
	}

	unsigned int N = input;


	int loopCount;
	int numberOfDigits = digitsCount(N);

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
		int leftDigit = (N % power(10, numberOfDigits - i)) / power(10, numberOfDigits - i - 1);
		int rightDigit = (N % power(10, 1 + i)) / power(10, i);

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
		else if (numberOfDigits % 2 != 0 && i == loopCount - 1)
		{
			checkForFirstWinner();

			cout << rightDigit;
		}
	}
}

