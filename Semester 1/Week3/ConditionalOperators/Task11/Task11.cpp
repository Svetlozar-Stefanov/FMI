#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;
	int d;
	int e;

	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;

	

	if ((a <= e && e <= b)  || (c <= e && e <= d))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}

	if ((a <= e && e <= b) && (c <= e && e <= d))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}

	if ((a <= e && e <= b) && (c > e || e > d))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}

	if (((a <= e && e <= b) || (c <= e && e <= d)) 
		&& (a <= e && e <= b) && (c > e || e > d)
		|| !((a <= e && e <= b) && (c > e || e > d)))
	{
		cout << "true ";
	}
	else
	{
		cout << "false ";
	}
}