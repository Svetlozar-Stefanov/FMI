#include <iostream>

using namespace std;

int main()
{
	int  n;

	cin >> n;

	if (n > 1)
	{
		for (int i = n; i >= 1; i--)
		{
			cout << i << "\n";
		}
	}
	if (n < 1)
	{
		for (int i = n; i <= 1; i++)
		{
			cout << i << "\n";
		}
	}

	
}