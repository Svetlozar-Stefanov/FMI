#include <iostream>
#include <string>

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

bool isAlphabetical(char arr[30][100], int bookN)
{
	bool result = true;
	for (int i = 0; i < bookN; i++)
	{
		for (int j = i; j < bookN; j++)
		{
			char n1 = arr[i][0];
			char n2 = arr[j][0];

			if (n1 > n2)
			{
				result = false;
				return result;
			}
		}
	}

	return result;
}

void getPassDigits(char title[]) 
{
	int counter = 0;
	for (int i = 0; i <= strlen(title); i++)
	{
		if (title[i] == ' ' || title[i] == '\0')
		{
			cout << counter << " ";
			counter = 0;
			continue;
		}
		counter++;
	}
}

int main()
{
	char library[20][30][100];
	int rows;
	int cols;
	cin >> rows;
	cin >> cols;
	cin.ignore();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			
			cin.getline(library[i][j], 100);
		}
	}

	for (int i = 0; i < rows; i++)
	{
		if (isAlphabetical(library[i], cols))
		{
			int bookIndex = cols % 2 == 0 ? cols / 2 - 1 : cols / 2;
			if (bookIndex >= 0 && bookIndex < cols)
			{
				getPassDigits(library[i][bookIndex]);
			}
		}

	}
}
