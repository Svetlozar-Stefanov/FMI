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

int main()
{
	char arr[100];
	cin >> arr;

	for (int i = 0; i < strlen(arr); i++)
	{
		for (int j = 0; j < strlen(arr) - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < strlen(arr); i++)
	{
		cout << arr[i];
	}
}