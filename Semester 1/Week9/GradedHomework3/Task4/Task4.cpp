#include <iostream>

using namespace std;

unsigned strlen(const char str[])
{
	unsigned counter = 0;

	int index = 0;
	while (str[index] != '\0')
	{
		counter++;
		index++;
	}

	return counter;
}

bool containsInPrevious(const char str[], const int index)
{
	bool contains = false;
	for (int i = index - 1; i >= 0; i--)
	{
		if (str[i] == str[index])
		{
			contains = true;
			break;
		}
	}

	return contains;
}

int longestSubstrWithUniqueSymbolsLength(const char str[])
{
	int maxLen = 1;
	int tempLen = 0;

	for (int i = 1; i < strlen(str); i++)
	{
		if (!containsInPrevious(str, i))
		{
			tempLen++;
		}
		else if (maxLen < tempLen)
		{
			maxLen = tempLen;
		}
	}

	if (maxLen < tempLen)
	{
		maxLen = tempLen;
	}

	return maxLen;
}

int main()
{
	char ch[100];

	cin >> ch;

	cout << longestSubstrWithUniqueSymbolsLength(ch);
}
