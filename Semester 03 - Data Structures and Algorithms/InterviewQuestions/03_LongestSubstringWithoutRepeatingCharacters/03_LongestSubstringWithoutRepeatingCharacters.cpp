#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
	if (s.size() == 1)
	{
		return 1;
	}

	int max = INT_MIN;
	for (int start = 0; start < s.size(); start++)
	{
		int counter[256] = { 0 };
		bool flag = true;
		for (int i = start; i < s.size(); i++)
		{
			counter[s[i]]++;
			if (counter[s[i]] > 1)
			{
				if (max < i - start)
				{
					max = i - start;
				}
				flag = false;
				break;
			}
		}
		if (flag)
		{
			int size = s.size() - start;
			if (max < size)
			{
				max = size;
			}
		}
	}

	if (max == INT_MIN)
	{
		return 0;
	}
	return max;
}

int main()
{
    std::cout << lengthOfLongestSubstring("au");
}
