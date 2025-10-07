#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;

		int count[256] = { 0 };
		for (int i = 0; i < str.length(); i++)
		{
			count[str[i]]++;
		}

		bool hasSingle = false;
		bool isPalindrome = true;
		for (int i = 0; i < 256; i++)
		{
			if (count[i] == 0)
			{
				continue;
			}

			if (str.length() % 2 != 0 && count[i] % 2 != 0 && !hasSingle)
			{
				hasSingle = true;
			}
			else if (str.length() % 2 != 0 && count[i] % 2 != 0 && hasSingle)
			{
				isPalindrome = false;
				break;
			}
			else if (count[i] % 2 != 0)
			{
				isPalindrome = false;
				break;
			}
		}

		cout << ((isPalindrome) ? "TRUE" : "FALSE") << "\n";
	}
}
