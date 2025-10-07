#include <iostream>

using namespace std;

bool isTriangleMain(const int arr[100][100], const int n)
{
	bool isTriangle = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (i != j)
			{
				if (!(arr[i][j] == 0 || arr[j][i] == 0))
				{
					isTriangle = false;
					break;
				}
			}

		}
		if (!isTriangle)
		{
			break;
		}
	}

	return isTriangle;
}

bool isTriangleSecond(const int arr[100][100], const int n)
{
	bool isTriangle = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = n - i - 1; j >= 0; j--)
		{
			if (j != n - 1 - i)
			{
				if (!(arr[i][j] == 0 || arr[j][i] == 0))
				{
					isTriangle = false;
					break;
				}
			}
		}
		if (!isTriangle)
		{
			break;
		}
	}

	return isTriangle;
}

int main()
{
	int arr[100][100];
	int n;

	cin >> n;
	if (n < 2 || n > 100)
	{
		return 1;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	bool isTriangle = isTriangleMain(arr, n);
	if (!isTriangle)
	{
		isTriangle = isTriangleSecond(arr, n);
	}
	
	cout << isTriangle;
}