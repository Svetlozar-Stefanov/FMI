#include <iostream>

using namespace std;

int calculate(const int a, const int b, const char action = '+')
{
	if (action == '+')
	{
		return a + b;
	}
	if (action == '-')
	{
		return a - b;
	}
	if (action == '*')
	{
		return a * b;
	}
	if (action == '/')
	{
		return a / b;
	}
}

int main()
{
	cout << calculate(6, 2);
	cout << calculate(6, 2, '+');
	cout << calculate(6, 2, '-');
	cout << calculate(6, 2, '*');
	cout << calculate(6, 2, '/');
}
