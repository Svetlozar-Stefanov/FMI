#include <iostream>

bool isBigger(int * a, int * b) 
{
	if (a > b)
	{
		return true;
	}
	return false;
}

int main()
{
	int a = 5;
	int b = 14;

	int* aP = &a;
	int* bP = &b;

	std::cout << aP << '\n';
	std::cout << bP << '\n';
	std::cout << isBigger(aP,bP) << '\n';
}