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
	char searched[] = { '!' , '?' , ',' };
	int size = sizeof(searched);
	int matches[3] = {};

	cin.getline(arr, 100);

	for (int i = 0; i < strlen(arr); i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[i] == searched[j])
			{
				matches[j]++;
				break;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		cout << searched[i] << " - " << matches[i] << endl;
	}
}
