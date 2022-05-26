#include "Functions.h"

unsigned int strleng(const char* str)
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	return i;
}

char* copy(const char* str)
{
	unsigned int size = strleng(str);
	char* newStr = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		newStr[i] = str[i];
	}
	newStr[size] = '\0';

	return newStr;
}

unsigned dCount(int n)
{
	int i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return i;
}

char* itos(int n)
{
	int c = dCount(n);
	char* num = new char[c+1];
	for (int i = c - 1; i >= 0; i--)
	{
		num[i] = n % 10 + '0';
		n /= 10;
	}
	num[c] = '\0';

	return num;
}

