#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::string;

static int indices[1000000];
static int scores[1000000];
static string names[1000000];

bool isLexicographicallyBigger(string& s1, string& s2) {
	int i1 = 0;
	int i2 = 0;
	while (s1[i1] != '\0' && s2[i2] != '\0')
	{
		if (s1[i1] > s2[i2]){
			return false;
		}
		else if (s1[i1] < s2[i2]) {
			return true;
		}

		i1++;
		i2++;
	}

	if (s1[i1] == '\0')
	{
		return true;
	}

	return false;
}

void swap(int * arr, int i1, int i2)
{
	int temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}


int partition(int* arr, int l, int r)
{
	int pivot = arr[r];

	int s = l;
	for (int i = l; i < r; i++)
	{
		if (scores[arr[i]] > scores[pivot])
		{
			swap(arr, s, i);
			s++;
		}
		if (scores[arr[i]] == scores[pivot] && isLexicographicallyBigger(names[arr[i]], names[pivot]))
		{
			swap(arr, s, i);
			s++;
		}
	}
	swap(arr, s, r);

	return s;
}

void quicksortHelper(int * arr, int l, int r) {
	if (l >= r)
	{
		return;
	}

	int m = partition(arr, l, r);

	quicksortHelper(arr, l, m - 1);
	quicksortHelper(arr, m + 1, r);
}

void quicksort(int * arr, int size) {
	quicksortHelper(arr, 0, size - 1);
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> names[i];
		indices[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> scores[i];
	}

	quicksort(indices, N);

	for (int i = 0; i < N; i++)
	{
		cout << names[indices[i]] << " " << scores[indices[i]] << '\n';
	}
}