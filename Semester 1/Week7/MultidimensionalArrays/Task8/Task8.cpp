#include <iostream>

using namespace std;

int main()
{
	int arr[25][25];
	int n;
	int s;

	cin >> n;
	cin >> s;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i + j == s)
			{
				sum += arr[i][j];
			}
		}
	}
	cout << sum;
}