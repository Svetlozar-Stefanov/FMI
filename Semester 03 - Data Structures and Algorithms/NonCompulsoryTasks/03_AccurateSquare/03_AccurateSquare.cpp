#include <iostream>
#include <vector>

using namespace std;

int64_t findClosestPerfectCube(vector<int64_t> &arr, int64_t num, int l, int r) {
	if (r - l <= 1)
	{
		if (arr[r] <= num)
		{
			return arr[r];
		}
		else
		{
			return arr[l];
		}
	}

	int middle = l + (r - l) / 2;
	if (num > arr[middle])
	{
		return findClosestPerfectCube(arr, num, middle, r);
	}
	else if(num < arr[middle])
	{
		return findClosestPerfectCube(arr, num, l, middle);
	}

	return arr[middle];
}

int main()
{
	int64_t points = 0;
	cin >> points;

	int count = 0;

	vector<int64_t> perfectCubes;
	for (int64_t i = 1; i <= points; i++)
	{
		if (i * i * i > points)
		{
			break;
		}
		perfectCubes.push_back(i * i * i);
	}

	points -= perfectCubes.back();
	cout << perfectCubes.back() << "\n";
	cout << points << "\n";
	count++;

	while (points > 0)
	{
		uint64_t cube = findClosestPerfectCube(perfectCubes, points, 0, perfectCubes.size() - 1);
		cout << cube << "\n";
		points -= cube;
		cout << points << "\n";
		count++;
	}

	cout << count;
}