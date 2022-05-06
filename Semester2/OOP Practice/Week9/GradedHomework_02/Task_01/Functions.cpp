#include "Functions.h"

unsigned int strleng(const char* str)
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

unsigned digitsCount(int n)
{
	int count = 0;
	do
	{
		count++;
		n /= 10;
	} while (n != 0);

	return count;
}

char* numToStr(int n)
{
	int size = digitsCount(n);
	char* sNum = new char[size+1];

	for (int i = size - 1; i >= 0; i--)
	{
		sNum[i] = (n % 10) + '0';
		n /= 10;
	}
	sNum[size] = '\0';

	return sNum;
}

int strToNum(const char* str)
{
	if (str == nullptr)
	{
		return -1;
	}

	int num = 1;
	for (int i = 0; i < strleng(str); i++)
	{
		num *= str[i] - '0';
		num *= 10;
	}

	if (strleng(str) > 1)
	{
		num /= 10;
	}

	return num;
}

char* append(const char* str1, const char* str2)
{
	int size = strleng(str1) + strleng(str2) + 1;
	char* newStr = new char[size];
	int index = 0;

	for (int i = 0; i < strleng(str1); i++)
	{
		newStr[index] = str1[i];
		index++;
	}

	for (int i = 0; i < strleng(str2); i++)
	{
		newStr[index++] = str2[i];
	}

	newStr[index++] = '\0';

	return newStr;
}

char* append(const char* str1, const char filler, const char* str2)
{
	if (str1 == nullptr || str2 == nullptr)
	{
		return nullptr;
	}

	int size = strleng(str1) + strleng(str2) + 2;
	char* newStr = new char[size];
	int index = 0;

	for (int i = 0; i < strleng(str1); i++)
	{
		newStr[index++] = str1[i];
	}

	newStr[index++] = filler;

	for (int i = 0; i < strleng(str2); i++)
	{
		newStr[index++] = str2[i];
	}

	newStr[index++] = '\0';

	return newStr;
}

char* copy(const char* str)
{
	if (str == nullptr)
	{
		return nullptr;
	}
	
	int size = strleng(str);
	char* strCopy = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		strCopy[i] = str[i];
	}
	strCopy[size] = '\0';

	return strCopy;
}

bool compare(const char* str1, const char* str2)
{
	unsigned int size1 = strleng(str1);
	unsigned int size2 = strleng(str2);
	if (size1 != size2)
	{
		return false;
	}

	for (int i = 0; i < size1; i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}

	return true;
}

bool contains(const myVector<unsigned int> &arr, const unsigned int n)
{
	for (int i = 0; i < arr.GetSize(); i++)
	{
		if (arr[i] == n)
		{
			return true;
		}
	}

	return false;
}

myVector<char*>* parse(const char* str, const char passEl, const unsigned int wordSize)
{	
	myVector<char*>* arr = new myVector<char*>;
	int temp = 0;
	char* newStr = new char[wordSize];
	for (int i = 0; i < strleng(str) + 1; i++)
	{
		if (str[i] == passEl || str[i] == '\0')
		{
			temp = 0;
			newStr = new char[wordSize];
			arr->Add(newStr);
		}
		newStr[temp++] = str[i];
	}

	return arr;
}
