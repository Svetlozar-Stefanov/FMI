#include <iostream>

int strleng(const char str[])
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

bool isValid(const char str[])
{
	if (strleng(str) != 7)
	{
		return false;
	}

	for (int i = 0; i < 4; i++)
	{
		if (i == 0 && str[i] == '0')
		{
			return false;
		}
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
	}

	if (str[4] != ' ')
	{
		return false;
	}
	if (str[5] != 'g')
	{
		return false;
	}
	if (str[6] != '.')
	{
		return false;
	}

	return true;
}

bool checkDate(const char str[]) 
{
	if (!isValid(str))
	{
		return false;
	}

	int num = 0;
	for (int i = 0; i < 4; i++)
	{
		num += str[i] - '0';
		num *= 10;
	}
	num /= 10;

	if (num % 4 == 0 || (num % 100 == 0 && num % 400 == 0))
	{
		return true;
	}

	return false;
}

int main()
{
	std::cout << checkDate("2010 g.");
}