#include <iostream>

using namespace std;

int main()
{
	int input;
	cin >> input;

	int i = 10;

	while (input / (i / 10) != 0)
	{
		cout << ((input % i) - (input % (i / 10))) / (i /10);

		i *= 10;
	}
}
