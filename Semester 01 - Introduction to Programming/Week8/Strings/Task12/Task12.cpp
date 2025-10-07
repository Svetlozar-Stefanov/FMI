#include <iostream>

using namespace std;

int strlen(char arr[])
{
	int counter = 0;
	int i = 0;
	while (arr[i] != '\0')
	{
		counter++;
		i++;
	}
	return counter;
}

int getAsNumber(char arr[])
{
	int number = 0;
	for (int i = 0; i < strlen(arr); i++)
	{
		int digit = (arr[strlen(arr) - 1 - i] - '0');
		number += digit * pow(10, i);
	}

	return number;
}

int main()
{
	char arr[100];
	cin >> arr;

	int num = getAsNumber(arr);	
	char numInHex[100];
	char hexDigits[] = { '0', '1', '2', '3', '4', '5','6','7','8', '9','A','B','C','D', 'E', 'F' };

	int index = 0;

	while (num > 0)
	{
		int reminder = num % 16;
		numInHex[index++] = hexDigits[reminder];
		num /= 16;
	}
	numInHex[index] = '\0';

	for (int i = strlen(numInHex) - 1; i >= 0; i--)
	{
		cout << numInHex[i];
	}
}
