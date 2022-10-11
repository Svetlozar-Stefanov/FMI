#include <iostream>
#include <vector>

using namespace std;

struct Student {
	unsigned score;
	string name;
};

bool isHigherUp(const string& s1, const string& s2)
{
	uint64_t i1 = 0;
	uint64_t i2 = 0;
	while (i1 < s1.size() && i2 < s2.size())
	{
		if (s1[i1] < s2[i2])
		{
			return true;
		}
		else if (s1[i1] > s2[i2])
		{
			return false;
		}
		i1++;
		i2++;
	}

	if (i1 >= s1.size())
	{
		return true;
	}
	return false;
}

void swap(vector<Student>& arr, int i1, int i2)
{
	Student temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

int randomized_partition(vector<Student>& arr, int l, int r)
{
	int pI = rand() % (r + 1);
	Student pivot = arr[pI];

	swap(arr, pI, r);

	int s = l;
	for (int i = l; i < r; i++)
	{
		if (arr[i].score > pivot.score)
		{
			swap(arr, s, i);
			s++;
		}
		else if ((arr[i].score == pivot.score) && isHigherUp(arr[i].name, pivot.name))
		{
			swap(arr, s, i);
			s++;
		}
	}
	swap(arr, s, r);

	return s;
}

void quicksortHelper(vector<Student>& arr, int l, int r) {
	if (l >= r)
	{
		return;
	}

	int m = randomized_partition(arr, l, r);

	quicksortHelper(arr, l, m - 1);
	quicksortHelper(arr, m + 1, r);
}

void quicksort(vector<Student>& arr) {
	quicksortHelper(arr, 0, arr.size() - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<Student> students(N);

	for (int i = 0; i < N; i++)
	{
		cin >> students[i].name;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> students[i].score;
	}

	quicksort(students);

	for (int i = 0; i < N; i++)
	{
		cout << students[i].name << " " << students[i].score << '\n';
	}
}