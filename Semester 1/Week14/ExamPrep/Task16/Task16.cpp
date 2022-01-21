#include <iostream>

int digitsCount(long N) 
{
    int count = 0;
	do
	{
		count++;
		N /= 10;
	} while (N != 0);

	return count;
}

int* getDigits(long N) 
{
	int size = digitsCount(N);

	int* digits = new int[size];
	for (int i = size - 1; i >= 0; i--)
	{
		digits[i] = N % 10;
		N /= 10;
	}

	return digits;
}

int AnalyzeNum(const long N) 
{
	int count[10] = { 0 };
	int* digits = getDigits(N);
	int size = digitsCount(N);
	for (int i = 0; i < size; i++)
	{
		count[digits[i]]++;
	}

	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		sum += count[i];
		if (sum == size - sum - count[i+1])
		{
			return i + 1;
		}
	}

	delete digits;

	return -1;
}

int main()
{
	std::cout << AnalyzeNum(52344537);
}