#include <iostream>

void swapCases(char str[]) 
{
	if (str == nullptr)
	{
		return;
	}

	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}

		i++;
	}
}

int main()
{
	char str[] = "BoY";
	swapCases(str);
	std::cout << str;
}