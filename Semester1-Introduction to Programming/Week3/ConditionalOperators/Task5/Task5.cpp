#include <iostream>

using namespace std;

int main()
{
	char input[4];

	cin >> input;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i != j && input[i] == input[j])
			{
				cout << "true";
				return 0;
			}
		}
	}
}