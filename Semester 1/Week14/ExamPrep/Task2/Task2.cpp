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

int* numOfWords(const char str[]) 
{
	if (str == nullptr)
	{
		return nullptr;
	}

	int wordCount[2] = {0};

	int count = 0;
	for (int i = 0; i <= strleng(str); i++)
	{
		if (str[i] != ' ' && str[i] != '\0')
		{
			count++;
		}
		else if (count != 0)
		{
			wordCount[count % 2]++;
			count = 0;
		}
	}

	return wordCount;
}

int main()
{
	int* count = numOfWords("This is an example string");
	std::cout << "{" << count[0] << "," << count[1] << "}";
}