#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cin >> input;

	string failureState = "0";

	int leftSum = 0;
	int rightSum = 0;

	for (int i = 0; i < 3; i++)
	{
		leftSum += input[i] - '0';
		rightSum += input[i + 3] - '0';

		if (i == 1 && input[i] < input[i + 2])
		{
			failureState = "32";
		}
	}

	if (leftSum == rightSum && failureState == "0")
	{
		cout << leftSum;
	}
	else if(leftSum == rightSum && failureState == "32")
	{
		cout << 32;
	}
	else if (leftSum != rightSum && failureState == "0")
	{
		cout << 31;
	}
	else if(leftSum != rightSum && failureState == "32")
	{
		cout << 30;
	}
}