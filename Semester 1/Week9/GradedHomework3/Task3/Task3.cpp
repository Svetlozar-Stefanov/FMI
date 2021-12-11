#include <iostream>

using namespace std;

const char capA = (char)55;
const char capB = (char)96;

int main()
{
	int a;
	int b;

	int maxPass;

	if (!(cin >> a) 
		|| a < 1 || a > 1000)
	{
		cout << "-1";
		return 1;
	}

	if (!(cin >> b)
		|| b < 1 || b > 1000)
	{
		cout << "-1";
		return 1;
	}

	if (!(cin >> maxPass)
		|| maxPass < 1 || maxPass > 1000000)
	{
		cout << "-1";
		return 1;
	}

	int passGenerated = 0;

	char A = (char)35;
	char B = (char)64;

	for (int x = 1; x <= a; x++)
	{
		for (int y = 1; y <= b; y++)
		{
			if (passGenerated >= maxPass)
			{
				return 0;
			}

			cout << A << B << x << y << B << A << '|';
			passGenerated ++;

			if (A >= capA)
			{
				A = 35;
			}
			else
			{
				A++;
			}

			if (B >= capB)
			{
				B = 64;
			}
			else
			{
				B++;
			}
		}
	}
}
