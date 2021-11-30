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

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] >= 65 && arr[i] <= 90)
		{
			arr[i] = arr[i] + 32;
		}
	}


	for (int i = 0; i < strlen(arr); i++)
	{
		cout << arr[i];
	}
}
