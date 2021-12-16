/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

unsigned strleng(const char str[])
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

bool containsInRange(const char str[], const int end, const int index)
{
	bool contains = false;
	for (int i = index - 1; i >= end; i--)
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
	int tempLen = 1;
	int end = 0;

	for (int i = 1; i < strleng(str); i++)
	{
		if (!containsInRange(str, end, i))
		{
			tempLen++;
		}
		else if (maxLen < tempLen)
		{
			maxLen = tempLen;
			tempLen = 1;
			end = i;
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
	char ch[101];

	if (!(cin >> ch))
	{
		cout << "-1";
		return 1;
	}

	cout << longestSubstrWithUniqueSymbolsLength(ch);

	return 0;
}
