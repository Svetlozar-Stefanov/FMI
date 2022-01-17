#include <iostream>

double digitsAvg(unsigned numb) 
{
	int count = 0;
	double sum = 0;

	while (numb != 0)
	{
		int current = numb % 10;

		sum += current;
		count++;

		numb /= 10;
	}

	return sum / count;
}

int main()
{
	std::cout << digitsAvg(1234);
}