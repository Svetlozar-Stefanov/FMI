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



	if (a + b > c && a + c > b && b + c > a)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
}