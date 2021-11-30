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
	cin.getline(arr, 100);
	
	int wordCount = 0;

	int i = 0;
	while (i <= strlen(arr))
	{
		if (i > 0 && arr[i - 1] != ' ' && arr[i] == ' ')
		{
			wordCount++;
			while (arr[i] == ' ')
			{
				i++;
			}

		}
		if (i > 0 && arr[i - 1] != ' ' && arr[i] == '\0')
		{
			wordCount++;
		}

		i++;
	}

	cout << wordCount;
}
