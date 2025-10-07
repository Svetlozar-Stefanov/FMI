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

bool contains(char ch, char arr[]) 
{
	bool isContaining = false;
	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] == ch)
		{
			isContaining = true;
			break;
		}
	}

	return isContaining;
}

int main()
{
	char arr1[100];
	cin.getline(arr1, 100);

	char arr2[100];
	cin.getline(arr2, 100);
	
	for (int i = 0; i < strlen(arr1); i++)
	{
		bool isContaining = !(contains(arr1[i], arr2));

		if (isContaining)
		{
			cout << arr1[i];
		}
	}
}
