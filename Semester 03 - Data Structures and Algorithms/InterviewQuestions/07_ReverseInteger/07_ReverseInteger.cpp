#include <iostream>

int reverse(int x) {
	bool isNegative = x < 0 ? true : false;
	int digits = 0;
	x = abs(x);
    int rev = 0;
	while (x > 0)
	{
		digits++;
		if (digits > 10 || (digits == 10 
			&& ((rev == 214748364 && x % 10 >= 7 + isNegative) || rev > 214748364)))
		{
			return 0;
		}
		rev *= 10;
		rev += x % 10;
		x /= 10;
	}

	return isNegative ? -rev : rev;
}

int main()
{
	std::cout << reverse(1534236469);
}
