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
	char arr1[100];
	cin.getline(arr1, 100);

	char arr2[100];
	cin.getline(arr2, 100);

	int count = 0;
	for (int i = 0; i < strlen(arr1); i++)
	{
		int index = 0;
		while (index < strlen(arr2) 
			&& i < strlen(arr1) 
			&& arr1[i] == arr2[index])
		{
			i++;
			index++;
		}
		if (index == strlen(arr2))
		{
			count++;
		}
	}

	cout << count;
}
