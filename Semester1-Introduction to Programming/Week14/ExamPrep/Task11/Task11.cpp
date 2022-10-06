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

char* revandreplace(const char* str)
{
	if (str == nullptr)
	{
		return nullptr;
	}

	int size = strleng(str);

	char* revStr = new char[size + 1];

	for (int i = size - 1; i >= 0; i--)
	{
		if (str[i] == 'e')
		{
			revStr[size - i - 1] = '!';
		}
		else if (str[i] == 'y')
		{
			revStr[size - i - 1] = '*';
		}
		else
		{
			revStr[size - i - 1] = str[i];
		}
	}
	revStr[size] = '\0';

	return revStr;
}

int main()
{
	char* str = revandreplace("I left you alone");
	std::cout << str;

}