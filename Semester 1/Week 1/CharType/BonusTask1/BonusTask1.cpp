#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;
    cin >> input;

	if (input.size() != 6)
	{
		return 0;
	}

	char letters[3] = { ' ',' ',' '};
	char numbers[3] = { ' ',' ',' ' };

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] >= 65 && input[i] <= 90)
		{
			int j = 0;
			while (input[i] > letters[j]
				&& j <= 2)
			{
				j++;
			}

			if (j - 1 < 0)
			{
				j = 0;
			}
			else
			{
				j--;
			}

			for (int k = 0; k < j; k++)
			{
				letters[k] = letters[k + 1];
			}

			letters[j] = input[i];
		}

		if (input[i] >= 48 && input[i] <= 57)
		{
			int j = 0;
			while (input[i] > numbers[j]
				&& j <= 2)
			{
				j++;
			}

			if (j - 1 < 0)
			{
				j = 0;
			}
			else
			{
				j--;
			}

			for (int k = 0; k < j; k++)
			{
				numbers[k] = numbers[k + 1];
			}

			numbers[j] = input[i];
		}
	}

	int j = 0;
	int l = 2;
	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 1)
		{
			cout << numbers[l];
			l--;
		}
		if (i % 2 == 0)
		{
			cout << letters[j];
			j++;
		}
	}


}
