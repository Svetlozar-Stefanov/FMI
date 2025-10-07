#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int l = 0; l <= 9; l++)
		{
			for (int j = 0; j <= 9; j++)
			{
				if (i + l + j >= 10 && i + l + j <= 99)
				{
					cout << i << l << j<<"\n";
				}
			}
		}
	}

	

	
}
