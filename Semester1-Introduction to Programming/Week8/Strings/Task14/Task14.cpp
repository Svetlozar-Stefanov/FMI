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

int main()
{
	string input;
	getline(cin, input);

	int mBI = 0;
	int mEI = 0;
	int maxDistance = INT_MIN;

	for (int i = 0; i < input.size(); i++)
	{
		for (int j = input.size() - 1; j > i; j--)
		{
			if (input[i] == input[j])
			{
				int distance = j - i;
				if (maxDistance < distance)
				{
					maxDistance = distance;
					mBI = i;
					mEI = j;
					break;
				}
			}
		}
	}

	cout << mBI << " " << mEI;
}
