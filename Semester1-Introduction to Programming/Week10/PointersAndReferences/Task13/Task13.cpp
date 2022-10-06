#include <iostream>

bool isPointingAtPointer(int** & a, int* & b) 
{
	if (a == &b)
	{
		return true;
	}
	return false;
}

int main()
{
	int a = 10;
	int* b = &a;
	int* g = &a;
	int** c = &b;

	std::cout << isPointingAtPointer(c, g);
}