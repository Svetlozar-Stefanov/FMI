#include <iostream>

using namespace std;

int main()
{
	int arr[10][10];
	int N;
	int M;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool hasRisingDiag = true;

	int i = 0;
	int row = 0;
	int col = 0;

	while (hasRisingDiag)
	{
		row = 0;
		col = 0;

		if (N - 2 - i >= 0)
		{
			row = N - 2 - i;
			if (row == 0)
			{
				i = 1;
			}
		}
		else
		{
			if (i < M - 1)
			{
				col = i;
			}
			else
			{
				break;
			}
		}
		
		while (row < N - 1 && col < M - 1)
		{
			if (arr[row][col] > arr[row + 1][col + 1])
			{
				hasRisingDiag = false;
				break;
			}
			row++;
			col++;
		}

		i++;
	}

	cout << hasRisingDiag;
}