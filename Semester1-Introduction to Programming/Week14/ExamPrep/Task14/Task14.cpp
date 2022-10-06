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

bool checkStr(const char* str)
{	
	for (int i = 0; i < strleng(str) - 1; i++)
	{
		char currentChar = str[i];
		char nextChar = str[i + 1];
		if (currentChar >= 'a' && currentChar <= 'z'
			&& (nextChar < 'A' || nextChar > 'Z'))
		{
			return false;
		}
		if (currentChar >= 'A' && currentChar <= 'Z'
			&& (nextChar < 'a' || nextChar > 'z'))
		{
			return false;
		}
	}

	return true;
}

int main()
{
    std::cout << checkStr("bAzC$aFbK");
}