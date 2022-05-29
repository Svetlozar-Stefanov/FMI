#include "Functions.h"

float abst(const float n)
{
	return n > 0.0f ? n : -n;
}

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
	do {
		n /= 10;
		i++;
	} while (n != 0);

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

char* ftos(float n)
{
	int dC = 0;
	float nc = n;
	float rem = nc - (int)nc;
	if (areEqual(rem, 0.0f))
	{
		return itos((int)nc);
	}
	else
	{
		while (!areEqual(rem, 0.0f))
		{
			nc *= 10;
			rem = nc - (int)nc;
			dC++;
		}
	}

	int c = dCount((int)nc);
	if ((int)n == 0)
	{
		c++;
	}

	char* num = new char[c + 2];
	for (int i = c; i >= 0; i--)
	{
		if (i == 0 && (int)n == 0)
		{
			num[i] = '0';
			continue;
		}
		if (c - i == dC)
		{
			num[i] = ',';
			continue;
		}
		num[i] = (int)nc % 10 + '0';
		nc /= 10;
	}
	num[c + 1] = '\0';

	return num;
}

bool areEqual(const float n1, const float n2)
{
	if (abst(n1-n2) < EPS)
	{
		return true;
	}
	return false;
}
