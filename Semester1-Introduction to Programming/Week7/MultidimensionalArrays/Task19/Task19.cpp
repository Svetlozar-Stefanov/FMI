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

	int s = 0;
	int row = 0;
	int col = 0;
	int e1 = (N % 2 == 0 ? 0 : 1);
	int e2 = (M % 2 == 0 ? 0 : 1);

	cout << endl;

	while (s < N / 2 + e1 && s < M / 2 + e2)
	{
		row = s;
		col = s;

		while (col < M - s)
		{
			cout << arr[row][col];
			col++;
			if (col == M - s)
			{
				col--;
				break;
			}
		}
		row++;
		cout << endl;
		
		while (row < N - s)
		{
			cout << arr[row][col];
			row++;
			if (row == N - s)
			{
				row--;
				break;
			}
		}
		col--;
		cout << endl;

		while (col >= s && row >= s && row < N - s)
		{
			cout << arr[row][col];
			col--;
			if (col < s)
			{
				col++;
				break;
			}
		}
		row--;
		cout << endl;

		s++;
		while (s < N / 2 + e1 && s < M / 2 + e2 && row >= s )
		{
			cout << arr[row][col] << " ";
			row--;
		}
		cout << endl;
	}
}