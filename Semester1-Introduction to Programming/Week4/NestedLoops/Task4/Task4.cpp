#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int input;

	cin >> input;

	for (int x = 1; x <= input; x++)
	{
		for (int y = 1; y <= input; y++)
		{
			for (int z = 1; z <= input; z++)
			{

				bool isRight = 2 * max(x, max(y, z)) * max(x, max(y, z)) == x * x + y * y + z * z;
				if (isRight)
				{
					cout << x << " " << y << " " << z << endl;
				}
			}
		}
	}
}

