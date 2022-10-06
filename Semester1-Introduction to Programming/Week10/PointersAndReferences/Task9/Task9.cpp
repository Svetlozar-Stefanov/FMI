#include <iostream>

void nullify(int* & p) 
{
	p = nullptr;
}

int main()
{
	int a = 10;
	int* aP = &a;

	nullify(aP);

	std::cout << aP << '\n';
}
