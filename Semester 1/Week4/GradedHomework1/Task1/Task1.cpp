#include <iostream>

using namespace std;

void printws(int numberOfWhitespaces) 
{
	for (int i = 0; i < numberOfWhitespaces; i++)
	{
		cout << " ";
	}
}

int main()
{
    int n;

    cin >> n;
	
	if (1 <= n && n <= 9)
	{
		for (int i = 1; i <= n; i++)
		{
			printws(i - 1);

			for (int j = i; j <= n; j++)
			{
				cout << j;
			}

			cout << "\n";
		}
		for (int i = n - 1; i >= 1; i--)
		{
			printws(n - 1);
			for (int j = n; j >= i; j--)
			{
				cout << j;
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "-1";
		return 1;
	}
}


