#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int output = 1;
	for (int i = n; i >= 1; i--)
	{
		output *= i;
	}

	cout << output;
}
