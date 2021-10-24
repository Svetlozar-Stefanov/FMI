#include <iostream>

using namespace std;

#define EPS 0.0000001;

int main()
{
	double a;

	cin >> a;
	
	int wholeA = a;

	if (a - wholeA == 0)
	{
		if (wholeA % 2 == 0)
		{
			cout << "Even interger";
		}
		else
		{
			cout << "Odd interger";
		}
	}
	else
	{
		if (a > 0)
		{
			cout << "Positive rational";
		}
		else
		{
			cout << "Negative rational";
		}
	}
}