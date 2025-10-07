#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int biggestNum = INT_MIN;

	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (input > biggestNum)
		{
			biggestNum = input;
		}
	}

	cout << biggestNum;
}
