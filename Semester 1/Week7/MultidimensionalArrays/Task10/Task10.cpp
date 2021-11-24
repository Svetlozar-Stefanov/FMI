#include <iostream>

using namespace std;

int main()
{
	int arr[25][25];
	int rows;
	int cols;
	int x;

	cin >> rows;
	cin >> cols;
	cin >> x;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool hasX = false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] == x)
			{
				hasX = true;
				break;
			}
		}
		if (hasX)
		{
			break;
		}
	}

	cout << hasX;
}