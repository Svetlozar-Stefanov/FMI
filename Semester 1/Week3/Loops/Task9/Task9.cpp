#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum = 0;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		sum += input;
	}

	cout << sum;
}
