#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;

	cin >> a;
	cin >> b;

	int output = 0;

	if (a + b > output)
	{
		output = a + b;
	}
	if (a - b > output)
	{
		output = a - b;
	}
	if (a * b > output)
	{
		output = a * b;
	}
	if (a / b > output)
	{
		output = a / b;
	}

	cout << output;
}