#include <iostream>

using namespace std;

int main()
{
	int input;

	cin >> input;

	for (int x = 0; x <= input; x++)
	{
		int y = input - x;
		cout << "x= " << x << " y= " << y << "\n";
	}
}
