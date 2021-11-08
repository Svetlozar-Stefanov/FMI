#include <iostream>

using namespace std;

int main()
{
    char input[12];

    cin >> input;

	int index = 0;
	int counter = 0;
	while (input[index++] != '\0')
	{
		counter++;
	}

	bool isPalindrome = true;
	for (int i = 0; i < counter / 2; i++)
	{
		if (input[i] != input[counter - i - 1])
		{
			isPalindrome = false;
			break;
		}
	}

	cout << isPalindrome;
}
