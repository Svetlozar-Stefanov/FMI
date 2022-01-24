#include <iostream>

int sumN(const int n) 
{
	if (n <= 0)
	{
		return 0;
	}
	if (n <= 1)
	{
		return 1;
	}

	return n + sumN(n - 1);
}

int main()
{
	std::cout << sumN(1);
}