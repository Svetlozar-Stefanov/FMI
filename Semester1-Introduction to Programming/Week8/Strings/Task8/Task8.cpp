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

int numberOfRepetitions(char arr1[], char arr2[]) 
{
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

	return count;
}

int main()
{
	char arr[100];
	cin.getline(arr, 100);

	char word1[100] = "begin";
	char word2[100] = "end";

	cout << (numberOfRepetitions(arr, word1) == numberOfRepetitions(arr, word2));
}
