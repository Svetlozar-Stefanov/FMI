#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int numN = 0;
	int numN1 = 0;
	int numN2 = 0;

	for (int i = 0; i <= n; i++)
	{
		if (i == 0)
		{
			numN2 = 0;
		}
		else if (i == 1)
		{
			numN1 = 1;
		}
		else
		{
			numN = numN1 + numN2;

			numN2 = numN1;

			numN1 = numN;
		}
	}

	cout << numN;
}
