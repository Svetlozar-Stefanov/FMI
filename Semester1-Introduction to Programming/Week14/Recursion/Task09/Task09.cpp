#include <iostream>

int digitsCount(const int num) 
{
	if (num == 0)
	{
		return 0;
	}

	return 1 + digitsCount(num/10);
}

int main()
{
    std::cout << digitsCount(1234);
}