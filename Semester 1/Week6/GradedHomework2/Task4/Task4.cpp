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

int shortestPath(const int startValue, const int target)
{
	int steps = 0;
	vector<vector<int>> variations;
	variations.push_back(getAsVector(startValue));

	vector<int> currentVar;
	vector<int> searchedVar = getAsVector(target);

	do
	{
		vector<vector<int>> currentDepthVar;

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

			int limit = currentVar.size();

			if (currentVar.size() < searchedVar.size())
			{
				for (int i = 0; i < limit; i++)
				{
					vector<int> temp = currentVar;
					temp.push_back(searchedVar[i]);

					currentDepthVar.push_back(temp);
				}
			}

			if (currentVar.size() > 0)
			{
				vector<int> temp = currentVar;
				temp.pop_back();

				currentDepthVar.push_back(temp);
			}

			

			for (int i = 0; i < limit - 1; i++)
			{
				for (int j = i + 1; j < limit; j++)
				{
					vector<int> temp = currentVar;

					int tempNum = temp[i];
					temp[i] = temp[j];
					temp[j] = tempNum;

					currentDepthVar.push_back(temp);
				}
			}
		}

		variations = currentDepthVar;
		steps++;
	}
	while (true);
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
