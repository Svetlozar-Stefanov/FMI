#include <iostream>

unsigned strleng(const char arr[]) 
{
	if (arr == nullptr)
	{
		return 0;
	}

	int i = 0;
	while (arr[i] != '\0')
	{
		i++;
	}

	return i;
}

int main()
{
	std::cout << strlen("bass");
}