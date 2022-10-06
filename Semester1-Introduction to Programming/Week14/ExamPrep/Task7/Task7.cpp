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

bool isValid(const char* num)
{
	int i = 0;
	if (num[i] == '-')
	{
		i++;
	}

	if (num[i] == '0')
	{
		return false;
	}

	for (; i < strleng(num); i++)
	{
		if (num[i] < '0' || num[i] > '9')
		{
			return false;
		}
	}

	return true;
}

long convertNumber(const char * num) 
{
	if (!isValid(num))
	{
		return -1;
	}

	int sum = 0;
	for (int i = 0; i < strleng(num); i++)
	{
		if (num[i] == '-')
		{
			continue;
		}
		sum += num[i];
	}

	return sum;
}

int main()
{
    std::cout << convertNumber("2343");
}