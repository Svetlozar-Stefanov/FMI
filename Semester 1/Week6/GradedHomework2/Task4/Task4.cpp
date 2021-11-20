#include <iostream>
#include <vector>

using namespace std;

int absOf(const int num)
{
	return num < 0 ? -num : num;
}

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

	for (int i = numberOfDigits - 1; i >= 0; i--)
	{
		digits.push_back(num / powerOf(10, i));

		num %= powerOf(10, i);
	}

	return digits;
}

unsigned timesOf(int num, vector<int> vec)
{
	unsigned reps = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (num == vec[i])
		{
			reps++;
		}
	}

	return reps;
}

unsigned matches(const vector<int> vec, const vector<int> target)
{
	unsigned matches = 0;

	int vecSize = vec.size();
	int tgSize = target.size();

	for (int i = 0; i < tgSize; i++)
	{
		if (i >= vecSize)
		{
			break;
		}
		else if (vec[i] == target[i])
		{
			matches++;
		}
	}

	return matches;
}

vector<int> getOptimalSwitch(const vector<int> vec, const vector<int> target)
{
	vector<int> optimalVec = vec;
	int vecSize = vec.size();

	int minMatches = matches(vec, target);
	for (int i = 0; i < vecSize - 1; i++)
	{
		for (int j = i + 1; j < vecSize; j++)
		{
			vector<int> temp = vec;

			int tempNum = temp[i];
			temp[i] = temp[j];
			temp[j] = tempNum;

			int nMatches = matches(temp, target);
			int lastDigit = temp[temp.size() - 1];
			if (timesOf(lastDigit, target) == 0)
			{
				nMatches++;
			}

			if (nMatches > minMatches)
			{
				minMatches = nMatches;
				optimalVec = temp;
			}
		}
	}

	return optimalVec;
}

vector<int> getOptimalAddition(const vector<int> vec, const vector<int> target)
{
	vector<int> optimal = vec;
	int tgSize = target.size();
	int minMatches = 0;

	for (int i = 0; i < tgSize; i++)
	{
		vector<int> temp = vec;

		if (timesOf(target[i], target) > timesOf(target[i], temp))
		{
			temp.push_back(target[i]);

			int nMatches = matches(getOptimalSwitch(temp, target), target);
			if (nMatches > minMatches)
			{
				minMatches = nMatches;
				optimal = temp;
			}
		}
	}

	return optimal;
}

int getShortesPath(const int start, const int end)
{
	vector<int> current = getAsVector(start);
	vector<int> target = getAsVector(end);
	int cntSize = current.size();
	int tgSize = target.size();

	int steps = 0;
	int minMatches;
	vector<int> optimal;
	while (current != target)
	{
		//Removes all excessive digits from the back of the array
		while (cntSize > 0
			&& timesOf(current[cntSize - 1], target) < timesOf(current[cntSize - 1], current))
		{
			current.pop_back();
			cntSize = current.size();
			steps++;
		}

		if (current == target)
		{
			break;
		}

		minMatches = 0;
		optimal = current;

		//Gets the optimal addition of digit
		if (cntSize <= tgSize)
		{
			optimal = getOptimalAddition(current, target);
		}
		minMatches = matches(optimal, target);

		//Gets the optimal switch of two digits and compares it to the addition
		vector<int> temp = getOptimalSwitch(current, target);
		int nMatches = matches(temp, target);
		int tempSize = temp.size();
		if (tempSize > 0
			&& timesOf(temp[tempSize - 1], target) == 0)
		{
			nMatches++;
		}
		if (nMatches > minMatches)
		{
			minMatches = nMatches;
			optimal = temp;
		}

		//Finally we get the most optimal of the two and iterate again
		current = optimal;
		cntSize = current.size();
		steps++;
	}

	return steps;
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

	cout << getShortesPath(n, k);
}