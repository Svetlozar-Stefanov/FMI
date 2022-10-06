#include <iostream>

int GCD(const int a, const int b) 
{
	if (b == 0)
	{
		return a;
	}

	int bigger = std::max(a, b);
	int smaller = std::min(a, b);

	return GCD(smaller, bigger % smaller);
}

int main()
{
    std::cout << GCD(81, 123);
}