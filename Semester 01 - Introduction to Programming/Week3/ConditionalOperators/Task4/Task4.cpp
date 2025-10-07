#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;

	cin >> a;
	cin >> b;
	cin >> c;

	if (a < b && a < c)
	{
		cout << a;
		if (b < c)
		{
			cout << b;
			cout << c;
		}
		else
		{
			cout << c;
			cout << b;
		}
		
	}
	if (b < a && b < c)
	{
		cout << b;
		if (a < c)
		{
			cout << a;
			cout << c;
		}
		else
		{
			cout << c;
			cout << a;
		}
	}
	if (c < a && c < b)
	{
		cout << c;
		if (b < a)
		{
			cout << b;
			cout << a;
		}
		else
		{
			cout << a;
			cout << b;
		}

	}
}