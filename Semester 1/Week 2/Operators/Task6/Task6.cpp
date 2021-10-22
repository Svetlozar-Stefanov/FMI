#include <iostream>

using namespace std;

int main()
{
    char input[5];

	cin >> input;

	for (int i = 3; i >= 0; i--)
	{
		cout << input[i];
	}

	return 0;
}
