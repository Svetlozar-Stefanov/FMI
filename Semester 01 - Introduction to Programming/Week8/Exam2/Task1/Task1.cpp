// Svetlozar Stefanov 4MI0600030

#include <iostream>

using namespace std;

const double PI = 3.14;

int main()
{
	double X;
	double Y;

	cin >> X;
	cin >> Y;

	double radiusP2 = X * X + Y * Y ;

	double area = PI * radiusP2;

	cout << area;
}
