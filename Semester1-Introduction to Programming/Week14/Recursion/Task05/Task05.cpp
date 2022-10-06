#include <iostream>

int C(const int m, const int n)
{
	if (m == 0 || n == 0 || m == n)
	{
		return 1;
	}

	return C(m - 1, n - 1) + C(m - 1, n);
}

int main()
{
	std::cout << C(6,2);
}