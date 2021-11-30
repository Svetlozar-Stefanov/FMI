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

    bool isPalindrome = true;
	int len = strlen(arr);

	for (int i = 0; i < len / 2; i++)
	{
		if (arr[i] != arr[len - 1 - i])
		{
			isPalindrome = false;
			break;
		}
	}

	cout << isPalindrome;
}

