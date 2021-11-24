#include <iostream>

using namespace std;

int main()
{
	int arr[100][100];
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

	for (int r = N - 1; r >= 0; r--)
	{
		for (int i = 0; i < r; i++)
		{
			int j = 0;
			while (j < M)
			{
				if (arr[i][j] > arr[i + 1][j])
				{
					for (int k = 0; k < M; k++)
					{
						int temp = arr[i][k];
						arr[i][k] = arr[i + 1][k];
						arr[i + 1][k] = temp;
					}
					break;
				}
				else if(arr[i][j] == arr[i + 1][j])
				{
					j++;
				}
				else
				{
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j];
		}
		cout << endl;
	}
}