#include <iostream>

using namespace std;

int main()
{
	int arr[25][25];
	int rows;
	int cols;

	cin >> rows;
	cin >> cols;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool hasNegative = false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] < 0)
			{
				hasNegative = true;
				break;
			}
		}
		if (hasNegative)
		{
			break;
		}
	}

	cout << hasNegative;
}