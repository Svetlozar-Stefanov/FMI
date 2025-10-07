#include <iostream>
#include <string>

using namespace std;

string* sortLexic(unsigned int n, string* ch) 
{
	string* sorted = new string[n];

	for (int i = 0; i < n; i++)
	{
		int index = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}

			int tI = 0;
			while (tI < ch[i].size() && tI < ch[j].size())
			{
				if (ch[i][tI] > ch[j][tI])
				{
					index++;
					break;
				}
				else if(ch[i][tI] == ch[j][tI])
				{
					tI++;
				}
				else
				{
					break;
				}
			}
			if (tI == ch[i].size()|| tI == ch[i].size() && ch[i].size() > ch[j].size())
			{
				index++;
			}

		}

		sorted[index] = ch[i];
	}

	return sorted;
}

int main()
{
	int n;
	cin >> n;

	string* arr = new string[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	string* sorted = sortLexic(n,arr);

	for (int i = 0; i < n; i++)
	{
		cout << sorted[i] << " ";
	}

	delete[] arr;
	delete[] sorted;
}