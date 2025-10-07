#include <iostream>

using namespace std;

int main()
{
	double number;
	cin >> number;
	char operation = ' ';

	double output = number;

	while (true)
	{
		cin >> operation;
		if (operation == '=')
		{
			break;
		}
		cin >> number;

		if (operation == '+')
		{
			output += number;
		}
		else if (operation == '-')
		{
			output -= number;
		}
		else if (operation == '*')
		{
			output *= number;
		}
		else if (operation == '/')
		{
			output /= number;
		}
	}

	cout << output;
}
