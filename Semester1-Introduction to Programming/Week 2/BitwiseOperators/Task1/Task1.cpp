#include <iostream>

using namespace std;

int main()
{
    int input;

    cin >> input;

	if ((input & 1) == 1)
	{
		cout << "odd";
	}
	else
	{
		cout << "even";
	}
}

