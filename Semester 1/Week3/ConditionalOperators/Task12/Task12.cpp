#include <iostream>

using namespace std;

int main()
{
	char a;
	char b;
	char c;
	char d;
	char e;

	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;

	char capitalE;
	char lowE;
	if (e>=65 && e<=90)
	{
		capitalE = e;
		lowE = (int)e + 32;
	}
	else
	{
		capitalE = (int)e - 32;
		lowE = e;
	}



	if ((a <= capitalE && capitalE <= b) || (c <= lowE && lowE <= d))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}

	if ((a <= capitalE && capitalE <= b) && (c <= lowE && lowE <= d))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}

	if ((a <= capitalE && capitalE <= b) && (c > lowE || lowE > d))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}

	if (((a <= capitalE && capitalE <= b) || (c <= lowE && lowE <= d))
		&& (a <= capitalE && capitalE <= b) && (c > lowE || lowE > d))
	{
		cout << "true ";
	}
	else if (!((a <= capitalE && capitalE <= b) && (c > lowE || lowE > d)))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}
}