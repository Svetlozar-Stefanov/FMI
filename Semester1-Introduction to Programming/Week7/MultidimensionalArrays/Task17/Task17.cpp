#include <iostream>

using namespace std;

bool isPalindrome(int size, char matrix[10][10])
{
	bool palindrome = true;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size / 2; j++)
		{
			if (i == j
				&& matrix[i][j] != matrix[size - 1 - i][size - 1 - j])
			{
				palindrome = false;
				break;
			}
			if (i == size - 1 - j
				&& matrix[i][j] != matrix[j][i])
			{
				palindrome = false;
				break;
			}
			if (matrix[i][j] != matrix[i][size - 1 - j])
			{
				palindrome = false;
				break;
			}
			if (matrix[j][i] != matrix[size - 1 - j][i])
			{
				palindrome = false;
				break;
			}
		}
		if (!palindrome)
		{
			break;
		}
	}

	return palindrome;
}

int main()
{
	char matrix[10][10];
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << isPalindrome(N, matrix);
}