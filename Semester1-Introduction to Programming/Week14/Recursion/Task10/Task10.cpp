#include <iostream>

bool containsDigit(const int num, const int k) 
{
	if (num == 0)
	{
		return false;
	}
	if (num % 10 == k)
	{
		return true;
	}

	return containsDigit(num / 10, k);
}

int main()
{
    std::cout << containsDigit(1234,5);
}