/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 1
* @compiler VC
*
*/


#include <iostream>

using namespace std;

void printsp(const int numberOfSpaces)
{
	for (int i = 0; i < numberOfSpaces; i++)
	{
		cout << " ";
	}
}

int main()
{
	double input;

	unsigned int n;

	if (!(cin >> input)
		|| !(1 <= input && input <= 9)
		|| input - (int)input != 0)
	{
		cout << "-1";
		return 1;
	}

	n = input;

	for (int i = 1; i <= n; i++)
	{
		printsp(i - 1);

		for (int j = i; j <= n; j++)
		{
			cout << j;
		}

		cout << "\n";
	}
	for (int i = n - 1; i >= 1; i--)
	{
		printsp(n - 1);
		for (int j = n; j >= i; j--)
		{
			cout << j;
		}

		cout << "\n";
	}

	return 0;
}



