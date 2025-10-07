#include <iostream>

void toLowerCase(char str[]) 
{
	if (str == nullptr)
	{
		return;
	}

	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
}

int main()
{
	char arr[] = "BOY";
	toLowerCase(arr);

	std::cout << arr;
}