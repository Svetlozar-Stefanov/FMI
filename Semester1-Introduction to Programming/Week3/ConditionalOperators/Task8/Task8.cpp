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



	if (a != 0 || b != 0 || c != 0)
	{
		if (a > b && a > c)
		{
			cout << a;
			if (b < c)
			{
				cout << c;
				cout << b;
			}
			else
			{
				cout << b;
				cout << c;
			}

		}
		if (b > a && b > c)
		{
			cout << b;
			if (a < c)
			{
				cout << c;
				cout << a;
			}
			else
			{
				cout << a;
				cout << c;
			}
		}
		if (c > a && c > b)
		{
			cout << c;
			if (b < a)
			{
				cout << a;
				cout << b;
			}
			else
			{
				cout << b;
				cout << a;
			}

		}
	}
	else
	{
		cout << 0;
	}
}