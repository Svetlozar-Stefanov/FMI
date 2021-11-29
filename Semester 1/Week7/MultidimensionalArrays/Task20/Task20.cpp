#include <iostream>

using namespace std;

int main()
{
	int arr1[10][10];
	int N;
	int M;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr1[i][j];
		}
	}

	int arr2[10][10];
	int P;
	int Q;

	cin >> P;
	cin >> Q;

	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < Q; j++)
		{
			cin >> arr2[i][j];
		}
	}

	if (M != P)
	{
		return 1;
	}

	int element = 0;

	int result[10][10] = {};
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < Q; j++)
		{
			for (int l = 0; l < M; l++)
			{
				result[i][j] += arr1[i][l] * arr2[l][j];
			}

		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < Q; j++)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
}