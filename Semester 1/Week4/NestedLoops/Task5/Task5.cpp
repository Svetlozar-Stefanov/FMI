#include <iostream>

using namespace std;

int main()
{
	int b1;
	int b2;
	int b3;
	int p;

	cin >> b1;
	cin >> b2;
	cin >> b3;
	cin >> p;

	for (int i = 0; i <= b1; i++)
	{
		for (int j = 0; j <= b2; j++)
		{
			for (int k = 0; k <= b3; k++)
			{
				if (p == i + 2 * j + 5 * k)
				{
					cout << i << " " << j << " " << k << endl;
					break;
				}
			}
		}
	}
}
