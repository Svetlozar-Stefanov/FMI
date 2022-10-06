#include <iostream>

bool isPointing(int* pointer, int& prop) 
{
	if (pointer == &prop)
	{
		return true;
	}
	return false;
}

int main()
{
	int b = 10;
	int c = 15;

	int* a = &b;

	std::cout << isPointing(a, b) << "\n";
	std::cout << isPointing(a, c);
}