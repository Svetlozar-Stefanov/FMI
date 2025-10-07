#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	int input = 0;
	int number = 0;

	for (int i = pow(10, n - 1); i >= 1; i/=10)
	{
		cin >> input;
		number += i * input;
	}

	cout << number;
}
