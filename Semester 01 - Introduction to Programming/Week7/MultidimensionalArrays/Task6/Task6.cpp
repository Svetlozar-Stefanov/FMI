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

	for (int i = 0; i < n; i++)
	{
		if (arr[i][i] >= 0)
		{
			cout << arr[i][i] << " ";
		}
	}
}