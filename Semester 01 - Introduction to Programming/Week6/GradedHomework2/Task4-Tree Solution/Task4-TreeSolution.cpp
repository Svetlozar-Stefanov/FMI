#include <iostream>
#include <vector>

using namespace std;

unsigned powerOf(const unsigned num, const unsigned n)
{
	unsigned result = 1;

	for (int i = 0; i < n; i++)
	{
		result *= num;
	}

	return result;
}

unsigned digitsCount(int num)
{
	unsigned count = 0;

	do
	{
		num /= 10;
		count++;
	} while (num != 0);

	return count;
}

vector<int> getAsVector(int num)
{
	vector<int> digits;
	int numberOfDigits = digitsCount(num);

	while (num != 0)
	{
		digits.push_back(num / powerOf(10, numberOfDigits - 1));

		num %= powerOf(10, numberOfDigits - 1);

		numberOfDigits--;
	}

	return digits;
}

int matches(const vector<int> num, const vector<int> target)
{
	int matches = 0;

	int nSize = num.size();
	int kSize = target.size();

	for (int i = 0; i < kSize; i++)
	{
		if (i >= nSize)
		{
			break;
		}
		else if (num[i] == target[i])
		{
			matches++;
		}
	}

	return matches;
}


int shortestPath(const int startValue, const int target)
{
	int minMatches = 0;
	int steps = 0;
	vector<vector<int>> variations;
	variations.push_back(getAsVector(startValue));

	vector<int> currentVar;
	vector<int> searchedVar = getAsVector(target);

	vector<vector<int>> currentDepthVar;
	do
	{
		while (true)
		{
			if (variations.size() > 0)
			{
				currentVar = variations[0];
				variations.erase(variations.begin());
			}
			else
			{
				break;
			}

			if (currentVar == searchedVar)
			{
				return steps;
				break;
			}

			int currentSize = currentVar.size();
			int searchedSize = searchedVar.size();

			if (currentSize < searchedSize)
			{
				for (int i = 0; i < searchedSize; i++)
				{
					vector<int> temp = currentVar;
					temp.push_back(searchedVar[i]);

					int numbOfMatches = matches(temp, searchedVar);
					if (numbOfMatches > minMatches)
					{
						minMatches = numbOfMatches;
						currentDepthVar.push_back(temp);
					}
				}
			}

			if (currentVar.size() > 0)
			{
				vector<int> temp = currentVar;
				temp.pop_back();

				int numbOfMatches = matches(temp, searchedVar);
				if (numbOfMatches > minMatches)
				{
					minMatches = numbOfMatches;
					currentDepthVar.push_back(temp);
				}
			}



			for (int i = 0; i < currentSize - 1; i++)
			{
				for (int j = i + 1; j < currentSize; j++)
				{
					vector<int> temp = currentVar;

					int tempNum = temp[i];
					temp[i] = temp[j];
					temp[j] = tempNum;

					currentDepthVar.push_back(temp);
					int numbOfMatches = matches(temp, searchedVar);
					if (numbOfMatches > minMatches)
					{
						minMatches = numbOfMatches;
						currentDepthVar.push_back(temp);
					}
				}
			}
		}

		variations = currentDepthVar;
		steps++;
	} while (true);
}

int main()
{
	int n;
	int k;

	if (!(cin >> n) || !(cin >> k))
	{
		cout << "-1";
		return 1;
	}

	cout << shortestPath(n, k);
}
