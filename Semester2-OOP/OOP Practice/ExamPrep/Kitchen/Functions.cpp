#include "Functions.h"

int slen(const char* str)
{
	if (str == nullptr)
	{
		return -1;
	}

	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}

	return count;
}

void scopy(char* &org, const char* cpy)
{
	if (cpy == nullptr)
	{
		return;
	}

	int size = slen(cpy);
	org = new char[size + 1];

	for (int i = 0; i < size; i++)
	{
		org[i] = cpy[i];
	}
	org[size] = '\0';
}
