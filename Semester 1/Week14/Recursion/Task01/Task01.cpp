#include <iostream>

int helper(const int x1, const int x2, const int step) 
{
	if (step <= 0)
	{
		return x2;
	}
	return helper(x2, x1 + x2, step - 1);
}

int fibbonachi(const unsigned n) 
{
	if ( n == 1 )
	{
		return 0;
	}
	if (n == 2)
	{
		return 1;
	}

	return helper(0, 1, n-2);
}

int main()
{
    std::cout << fibbonachi(8);
}