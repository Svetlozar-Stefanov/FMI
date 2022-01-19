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

bool isLC(const char l) 
{
	if (l >= 'a' && l <= 'z')
	{
		return true;
	}

	return false;
}

bool isUC(const char l)
{
	if (l >= 'A' && l <= 'Z')
	{
		return true;
	}

	return false;
}

int* cntWords(const char str[]) 
{
	if (str == nullptr)
	{
		return nullptr;
	}

	int result[2] = {0};
	
	int start = 0;
	for (int i = 0; i <= strleng(str); i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			bool isValid = true;
			for (int j = start; j < i; j++)
			{
				if (isLC(str[start]) && !isLC(str[j]))
				{
					isValid = false;
					break;
				}
				if (isUC(str[start]) && !isUC(str[j]))
				{
					isValid = false;
					break;
				}
			}
			if (isValid)
			{
				if (isLC(str[start]))
				{
					result[0]++;
				}
				else if (isUC(str[start]))
				{
					result[1]++;
				}
			}
			start = i + 1;

		}
	}

	return result;
}

int main()
{
	int* words = cntWords("This IS an exAMple STRING F&OR this eXErcise.");

	std::cout << words[0] << " " << words[1];
}