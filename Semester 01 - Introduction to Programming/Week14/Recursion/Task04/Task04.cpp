#include <iostream>

int pow(const int x, const int n) 
{
	if (n <= 0)
	{
		return 1;
	}

	return x * pow(x, n-1);
}

int main()
{
    std::cout << pow(2,6);
}