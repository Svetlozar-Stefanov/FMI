#pragma once
// Task1
int sum(const int arr[], const int I)
{
	int sum = 0;
	for (int i = 0; i < I; i++)
	{
		sum += arr[i];
	}

	return sum;
}

int analyzeArray(const int arr[], const int I)
{
	if (arr == nullptr)
	{
		return -1;
	}

	int arrSum = sum(arr, I);

	if (arrSum % 2 != 0)
	{
		return 0;
	}

	for (int i = 0; i < I; i++)
	{
		int tempSum = 0;
		for (int j = i; j < I; j++)
		{
			tempSum += arr[j];
			if (tempSum == arrSum / 2)
			{
				return 1;
			}
		}
	}

	return 0;
}

//Task2
int strleng(const char str[])
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return i;
}

int checkStr(const char str[])
{
	if (str == nullptr || strleng(str) < 2)
	{
		return -1;
	}

	int count[256] = { 0 };
	for (int i = 0; i < strleng(str); i++)
	{
		count[str[i]]++;
	}

	bool flag = false;
	for (int i = 0; i < 256; i++)
	{
		if (count[i] % 2 != 0 && !flag)
		{
			flag = true;
		}
		else if (count[i] % 2 != 0 && flag)
		{
			return 0;
		}
	}

	return 1;
}

//Task3
void convertNumber(long& num)
{
	long newNum = 0;

	do
	{
		newNum += num % 10;
		newNum *= 10;
		num /= 10;
	} while (num != 0);

	newNum /= 10;
	num = newNum;
}

//Task4
int getAsNum(const char str[])
{
	int num = 0;
	for (int i = strleng(str) - 1; i >= 0; i--)
	{
		num += str[i];
		num *= 10;
	}
	num /= 10;

	return num;
}

int checkTimeStr(const char str[])
{
	int size = strleng(str);

	if (size > 8)
	{
		return -1;
	}

	int hours = 0;
	for (int i = 0; i < 2; i++)
	{
		hours += str[i] - '0';
		hours *= 10;
	}
	hours /= 10;

	if (hours < 0 || hours > 24)
	{
		return -1;
	}

	int minutes = 0;
	for (int i = 3; i < 5; i++)
	{
		minutes += str[i] - '0';
		minutes *= 10;
	}
	minutes /= 10;

	if (minutes < 0 || minutes > 59)
	{
		return -1;
	}

	int sec = 0;
	for (int i = 6; i < 8; i++)
	{
		sec += str[i] - '0';
		sec *= 10;
	}
	sec /= 10;

	if (sec < 0 || sec > 59)
	{
		return -1;
	}

	if (hours == 24 && minutes != 0 && sec != 0)
	{
		return -1;
	}

	if (str[2] != ':' || str[5] != ':')
	{
		return -1;
	}

	return 1;
}

//Task5
bool contains(const char str[], const char ch)
{
	for (int i = 0; i < strleng(str); i++)
	{
		if (str[i] == ch)
		{
			return true;
		}
	}

	return false;
}

char* checkForRep(const char str[]) 
{
	if (str == nullptr)
	{
		return nullptr;
	}

	int counter[256] = {0};
	for (int i = 0; i < strleng(str); i++)
	{
		counter[str[i]]++;
	}

	char* rep = new char[strleng(str) + 1];

	int index = 0;
	for (int i = 0; i < strleng(str); i++)
	{
		if (counter[str[i]] > 1 && !contains(rep, str[i]))
		{
			rep[index++] = str[i];
		}
	}
	rep[index] = '\0';

	return rep;
}

//Task6
int digitsCount(long num)
{
	int count = 0;
	do
	{
		count++;
		num /= 10;
	} while (num != 0);
	
	return count;
}

long* getDigits(long num) 
{
	int count = digitsCount(num);
	long* digits = new long[count];

	for (int i = count - 1; i >= 0; i--)
	{
		digits[i] = num % 10;
		num /= 10;
	}

	return digits;
}

int numCalc(const long num, const int k, const int l) 
{
	int count = digitsCount(num);
	if (l > count || k > count || l == k || l < 1 || k < 1)
	{
		return -1;
	}
	long* digits = getDigits(num);

	return digits[k-1] + digits[l-1];
}

//Task8
bool doExist(const char * symbols, const char * word) 
{
	int sizeS = strleng(symbols);
	int sizeW = strleng(word);

	if (sizeW > sizeS)
	{
		return false;
	}

	int index = 0;
	for (int i = sizeS - 1; i >= 0; i--)
	{
		if (symbols[i] == word[index])
		{
			index++;
		}
		else
		{
			index = 0;
		}

		if (index == sizeW)
		{
			return true;
		}
	}

	return false;
}

//Task9
double calculateMatrix(const int ** matrix, const int m) 
{
	double sum = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				sum += matrix[i][j];
			}
			if (i == m - j - 1)
			{
				sum += matrix[i][j];
			}
		}
	}

	return sum;
}

//Task10
char* getWord(const char * str) 
{
	if (str == nullptr)
	{
		return nullptr;
	}
	int size = strleng(str);

	int start = 0;
	int max = 0;

	int index = 0;
	while (index < size)
	{
		while ((str[index] == ' ' 
			|| str[index] == '\t')
			&& index <= size)
		{
			index++;
		}

		int tempStart = index;
		int tempMax = 0;
		while (str[index] != ' '
			&& str[index] != '\t'
			&& str[index] !='\0'
			&& index <= size)
		{
			tempMax++;
			index++;
		}

		if (tempMax > max)
		{
			max = tempMax;
			start = tempStart;
		}
	}

	char* word = new char[max+1];
	for (int i = 0; i <  max; i++)
	{
		word[i] = str[i + start];
	}
	word[max] = '\0';

	return word;
}

//Task11
bool hasFixedElements(const int arr[], const int length) 
{
	if (arr == nullptr)
	{
		return false;
	}

	int count = 0;
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == i)
		{
			count++;
		}
	}

	if (count >= 2)
	{
		return true;
	}
	return false;
}