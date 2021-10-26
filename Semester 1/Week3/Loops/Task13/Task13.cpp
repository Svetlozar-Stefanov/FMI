#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if (n > 0)
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				cout << "No";
				return 0;
			}
		}
		
		cout << "Yes";
	}
}
