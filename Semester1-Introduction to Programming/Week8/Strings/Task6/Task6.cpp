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

	bool isUnique = true;
	for (int i = 0; i < strlen(arr); i++)
	{
		for (int j = 0; j < strlen(arr); j++)
		{
			if (i != j)
			{
				if (arr[i] >= 65 && arr[i] <= 90 && arr[i] == arr[j])
				{
					isUnique = false;
					break;
				}
			}

			if (isUnique)
			{
				break;
			}
		}
	}

	cout << isUnique;
}
