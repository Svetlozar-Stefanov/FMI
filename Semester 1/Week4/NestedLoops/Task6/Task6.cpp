#include <iostream>

using namespace std;

int main()
{
	int input;

	cin >> input;

	if (input <= 27)
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int i2 = 0; i2 <= 9; i2++)
			{
				for (int i3 = 0; i3 <= 9; i3++)
				{
					if (i + i2 + i3 == input)
					{
						cout << i << " " << i2 << " " << i3 << endl;
						break;
					}
				}
			}
		}
	}
}
