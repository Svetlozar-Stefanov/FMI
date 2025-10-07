#include <iostream>

using namespace std;

int main()
{
	int x = 0;
	
	cin >> x;

	int sum = 1;

	for (int i = 122; i >= 2; i -= 2)
	{
		sum = (sum * x) + i;
	}

	cout << sum;
}
