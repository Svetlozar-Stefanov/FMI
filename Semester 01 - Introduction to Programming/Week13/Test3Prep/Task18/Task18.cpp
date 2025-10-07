#include <iostream>

unsigned strleng(const char str[]) 
{
	if (str == nullptr)
	{
		return 0;
	}

	int i = 0;
	while (str[i++] != '\0');

	return i;
}

bool contains(const char str[], const char ch)
{
	if (str == nullptr)
	{
		return false;
	}

	for (int i = 0; i < strleng(str); i++)
	{
		if (str[i] == ch)
		{
			return true;
		}
	}

	return false;
}

bool containsUAndP(const char str[])
{
	return contains(str, 'U') && contains(str, 'P');
}

int main()
{
	std::cout << containsUAndP("Uo is the best");
}