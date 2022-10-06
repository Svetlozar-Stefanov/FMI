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
	
	bool isSymetrical = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && arr[i][j] != arr[n - 1 - i][n - 1 - j])
			{
				isSymetrical = false;
				break;
			}
		}
		if (!isSymetrical)
		{
			break;
		}
	}
	cout << isSymetrical;
}