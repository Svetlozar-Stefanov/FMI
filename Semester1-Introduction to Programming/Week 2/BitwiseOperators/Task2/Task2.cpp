#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
	int input;
	int m;

	cin >> input;
	cin >> m;

	m = pow(10, m - 1);

	int c = input & m;

	if (c != 0)
	{
		cout << "True";
	}
	else
	{
		cout << "False";
	}
}