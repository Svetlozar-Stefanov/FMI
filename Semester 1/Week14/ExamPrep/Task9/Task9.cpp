#include <iostream>

int strleng(const char* str)
{
	if (str == nullptr)
	{
		return -1;
	}

	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	return i;
}

int digitsCount(int num)
{
	int count = 0;
	do
	{
		count++;
		num /= 10;
	} while (num != 0);

	return count;
}

int* getDigits(int num)
{
	int count = digitsCount(num);
	int* digits = new int[count];
	for (int i = 0; i < count; i++)
	{
		digits[i] = num % 10;
		num /= 10;
	}

	return digits;
}

char* Encode(const char* str)
{
	if (str == nullptr)
	{
		return nullptr;
	}

	char* newChar = new char[strleng(str) * 6];
	int index = 0;
	for (int i = 0; i < strleng(str); i++)
	{
		int digCount = digitsCount((int)str[i]);
		int * digits = getDigits((int)str[i]);

		for (int j = digCount - 1; j >= 0; j--)
		{
			newChar[index++] = digits[j] + '0';
		}
		if (i < strleng(str) - 1)
		{
			newChar[index++] = '_';
		}
		
		delete[] digits;
	}

	newChar[index] = '\0';

	return newChar;
}

int main()
{
	std::cout << Encode("abc");
}