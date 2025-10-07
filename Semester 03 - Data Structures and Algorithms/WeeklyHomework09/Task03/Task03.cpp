#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, vector<int>> indices;

bool hasSubstr(string& s1, string& s2, int m)
{
	for (int i = 0; i < s1.size(); i++)
	{
		vector<int> occ = indices[s1[i]];
		for (int i2 = 0; i2 < occ.size(); i2++)
		{
			int j = occ[i2];
			bool valid = true;
			for (int offset = 0; offset < m; offset++)
			{
				if (i + offset >= s1.size()
					|| j + offset >= s2.size()
					|| s1[i + offset] != s2[j + offset])
				{
					valid = false;
					break;
				}
			}
			if (valid)
			{
				return true;
			}
		}
	}

	return false;
}

void helper(string& s1, string& s2, int l, int r, int& res)
{
	if (l >= r)
	{
		return;
	}

	int m = l + (r - l) / 2;

	if (hasSubstr(s1, s2, m))
	{
		if (res < m)
		{
			res = m;
		}
		helper(s1, s2, m + 1, r, res);
	}
	else
	{
		helper(s1, s2, l, m, res);
	}
}

int longestSubStr(string& s1, string& s2)
{
	int size = min(s1.size(), s2.size());

	int res = 0;
	helper(s1, s2, 1, size, res);
	return res;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	for (int i = 0; i < s2.size(); i++)
	{
		indices[s2[i]].push_back(i);
	}

	cout << longestSubStr(s1, s2);
}
