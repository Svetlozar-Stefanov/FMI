#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int l = 10;

	while (n / (l*10) != 0)
	{
		l *= 10;
	}

	for (int i = l; i > 0; i /= 100)
	{
		cout << ((n % i) - (n % (i / 10))) / (i / 10) << " ";
	}
}
