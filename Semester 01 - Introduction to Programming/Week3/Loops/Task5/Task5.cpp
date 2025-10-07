#include <iostream>

using namespace std;

int main()
{
	int a;
	int b;
	int c;

	cin >> a;
	cin >> b;
	cin >> c;

	while (a % c != 0)
	{
		a++;
	}

	for (int i = a; i <= b; i += c)
	{
		cout << i << "\n";
	}
}
