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

	int P;
	int	Q;

	cin >> P;
	cin >> Q;

	int maxSum = INT_MIN;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i + P - 1 < N && j + Q - 1 < M)
			{
				int sum = 0;
				for (int i1 = i; i1 < P + i; i1++)
				{
					for (int j1 = j; j1 < Q + j; j1++)
					{
						sum += arr[i1][j1];
					}
				}
				if (maxSum < sum)
				{
					maxSum = sum;
				}
			}
		}
	}

	cout << maxSum;
}