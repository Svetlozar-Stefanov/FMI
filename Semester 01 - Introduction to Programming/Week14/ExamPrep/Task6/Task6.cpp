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

long convertNumber(char* num) 
{
	if (num == nullptr || strleng(num) < 3)
	{
		return -1;
	}

	for (int i = 0; i < strleng(num); i++)
	{
		for (int j = 0; j < strleng(num) - i - 1; j++)
		{
			if (num[j] < num[j + 1])
			{
				char temp = num[j];
				num[j] = num[j + 1];
				num[j + 1] = temp;
			}
		}
	}

	return num[0] + num[1] + num[2];
}

int main()
{
	char str[] = "125364024";

	std::cout << convertNumber(str);
}