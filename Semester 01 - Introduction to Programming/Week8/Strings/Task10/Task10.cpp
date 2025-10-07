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
	char arr1[100];
	cin >> arr1;

	char arr2[100];
	cin >> arr2;

	if (getAsNumber(arr1) >= getAsNumber(arr2))
	{
		for (int i = 0; i < strlen(arr1); i++)
		{
			cout << arr1[i];
		}
	}
	else
	{
		for (int i = 0; i < strlen(arr2); i++)
		{
			cout << arr2[i];
		}
	}
}
