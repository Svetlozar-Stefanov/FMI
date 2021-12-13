#include <iostream>

void printAll(int* & p) 
{
	std::cout << &p << '\n';
	std::cout << &*p << '\n';
	std::cout << *p << '\n';
}

int main()
{
	int a = 10;
	int* p = &a;

	printAll(p);
}