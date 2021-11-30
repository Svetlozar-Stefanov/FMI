#include <iostream>
#include <vector>

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

bool contains(char ch, vector<char> arr)
{
	bool isContaining = false;
	for (int i = 0; i < arr.size(); i++)
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
	char arr[100];
	cin.getline(arr, 100);

	char alphabet[26];

	int index = 0;
	for (int i = 97; i <= 122; i++)
	{
		alphabet[index] = (char)i;
		index++;
	}
	
	vector<char> lettersToSkip;

	for (int i = 0; i < strlen(arr); i++)
	{
		if (arr[i] >= 97 && arr[i] <= 122
			&& !contains(arr[i], lettersToSkip))
		{
			lettersToSkip.push_back(arr[i]);
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (!contains(alphabet[i], lettersToSkip))
		{
			cout << alphabet[i];
		}
	}
}
