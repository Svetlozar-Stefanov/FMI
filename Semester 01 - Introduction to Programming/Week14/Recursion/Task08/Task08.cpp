#include <iostream>

int multiplyDigits(const int num)
{
	if (num == 0)
	{
		return 1;
	}

	return num % 10 * multiplyDigits(num / 10);
}

int main()
{
    std::cout << multiplyDigits(125);
}