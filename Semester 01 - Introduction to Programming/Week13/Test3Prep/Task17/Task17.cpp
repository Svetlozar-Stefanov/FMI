#include <iostream>

unsigned strleng(const char arr[])
{
	if (arr == nullptr)
	{
		return 0;
	}
	
	int i = 0;
	while (arr[i++] != 0);

	return i;
	
}

void replaceWith(char arr[], const char s1, const char s2) 
{
	for (int i = 0; i < strleng(arr); i++)
	{
		if (arr[i] == s1)
		{
			arr[i] = s2;
		}
	}
}

int main()
{
	char arr[] = "spass";
	replaceWith(arr, 's', 'p');
	std::cout << arr;
}
