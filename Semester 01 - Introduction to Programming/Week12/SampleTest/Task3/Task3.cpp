#include <iostream>

int digitsCount(int n) 
{
	int count = 0;
	do
	{
		n /= 10;
		count++;
	} while (n > 0);

	return count;
}

int* getDigits(int n) 
{
	int count = digitsCount(n);
	int* arr = new int[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = n % 10;
		n /= 10;
	}

	return arr;
}

int* Extract(const int num) 
{
	int n = abs(num);
	int* digits = getDigits(n);
	int size = digitsCount(n);

	int count[10] = {};

	int maxCount = -1;
	int numberOfMax = 0;
	for (int i = 0; i < size; i++)
	{
		count[digits[i]]++;
		if (maxCount < count[digits[i]])
		{
			maxCount = count[digits[i]];
			numberOfMax = 1;
		}
		else if (maxCount == count[digits[i]])
		{
			numberOfMax++;
		}
	}

	int index = 0;
	int* mostCommon = new int[numberOfMax + 1];
	for (int i = 0; i < 10; i++)
	{
		if (count[i] == maxCount)
		{
			mostCommon[index++] = i;
		}
	}
	mostCommon[index] = -1;

	delete[] digits;

	return mostCommon;
}

int main()
{
	int* mostCommon = Extract(-223441);
	int i = 0;
	while (mostCommon[i] != -1)
	{
		std::cout << mostCommon[i++] << " ";
	}

	delete[] mostCommon;
}