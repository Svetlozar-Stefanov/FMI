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

int* getWord(const char str[]) 
{
	if (str == nullptr)
	{
		return nullptr;
	}

	int res[2] = { 0 };

	int start = 0;
	for (int i = 0; i <= strleng(str); i++)
	{	
		while ((str[i] == ' ' 
			|| str[i] == '\0' 
			|| str[i] == '\t')
			&& i < strleng(str))
		{
			i++;
		}

		if (str[i] == '\0')
		{
			break;
		}

		if (str[i] == 'a')
		{
			res[0]++;
		}
		res[1]++;

		while ((str[i] != ' '
			&& str[i] != '\t')
			&& i < strleng(str))
		{
			i++;
		}
	}

	return res;
}

int main()
{
	int* res = getWord(" It	    ass  about      an hour to                  answer all the questions.");
	std::cout << res[0] << res[1];
}
