#include <iostream>
#include <vector>
#include <climits>

using namespace std;

bool isValidSum(vector<int>& skills, int64_t candidate, int T)
{
	int count = 1;
	int64_t subSum = 0;
	uint64_t index = 0;
	while (index < skills.size())
	{
		if (skills[index] > candidate)
		{
			return false;
		}

		if (subSum + skills[index] <= candidate)
		{
			subSum += skills[index];
		}
		else
		{
			subSum = skills[index];
			count++;
		}

		index++;
	}

	if (count > T)
	{
		return false;
	}
	return true;
}

void findMinimumSkillSum(vector<int> &skills, int64_t lowRange, int64_t highRange, int T, int64_t&result) {
	if (lowRange > highRange)
	{
		return;
	}

	int64_t candidateSum = lowRange + (highRange - lowRange) / 2;

	if (isValidSum(skills, candidateSum, T))
	{
		result = candidateSum;
		findMinimumSkillSum(skills, lowRange, candidateSum-1, T, result);
	}
	else
	{
		findMinimumSkillSum(skills, candidateSum + 1, highRange, T, result);
	}
}

int main()
{
    int N, T;
	cin >> N >> T;
    vector<int> skills(N);

	int64_t sum = 0;
	int64_t max = INT_MIN;
	for (int i = 0; i < N; i++)
	{
		cin >> skills[i];
		sum += skills[i];
		if (max < skills[i])
		{
			max = skills[i];
		}
	}

	int64_t result = 0;
	findMinimumSkillSum(skills, max, sum, T, result);

	cout << result;
}
