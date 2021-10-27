#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int x;
	int y;

	cin >> x;
	cin >> y;

	for (int i = 1; i < y; i++)
	{
		cout << "|";
		for (int j = 1; j < y; j++)
		{
			if (i == 1 && j == 1)
			{
				cout << "X" << "|";
				j = x;
			}
			else if (j == 1)
			{
				cout << i << "|";
				j = x;
			}

			cout<< setw(3) << j * i << "|";

		}
		cout << endl;

		if (i == 1)
		{
			i = x - 1;
		}
	}
}
