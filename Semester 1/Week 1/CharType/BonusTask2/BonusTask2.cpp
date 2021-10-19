#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cin >> input;

	if (input.size() != 8)
	{
		return 0;
	}

	int letterSum = 0;
	int multipliedNum = 1;

	for (int i = 0; i < 6; i++)
	{
		if (i >= 0 && i < 2)
		{
			letterSum += (int)input[i] + (int)input[7 - i];
		}

		if (i >= 2 && i < 6)
		{
			multipliedNum *= (int)input[i] - '0';
		}
	}

	if (letterSum / 10 == multipliedNum)
	{
		cout << "Yes " << multipliedNum;
	}
	else
	{
		cout << "No";
	}
}
