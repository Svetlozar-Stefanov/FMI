#include <iostream>

using namespace std;

int main()
{
	int arr[25][25];
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int result = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != n - 1 - i)
			{
				result *= arr[i][j];
			}
		}
	}
	cout << result;
}