#include <iostream>
#include <vector>

using namespace std;

struct GymRat
{
	int d;
	int t;
};

vector<GymRat> boys;
int indices[1000000] = { 0 };

bool isStronger(GymRat &g1, GymRat &g2) {
	if (g1.d * g2.t > g2.d * g1.t)
	{
		return true;
	}
	else if (g1.d * g2.t == g2.d * g1.t && g1.d > g2.d)
	{
		return true;
	}

	return false;
}

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int partition(int* arr, int l, int r) {
	int pivot = arr[r];

	int index = l;
	for (int i = l; i < r; i++)
	{
		if (!isStronger(boys[arr[i]], boys[pivot])) {
			swap(arr, index, i);

			index++;
		}
	}
	swap(arr, index, r);

	return index;
}

void quicksortHelper(int* arr, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int part = partition(arr, l, r);

	quicksortHelper(arr, l, part - 1);
	quicksortHelper(arr, part + 1, r);
}

void quicksort(int* arr, int size) {
	quicksortHelper(arr, 0, size - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		GymRat g;
		cin >> g.d;
		cin >> g.t;

		boys.push_back(g);
		indices[i] = i;
	}

	quicksort(indices, N);

	cout << '\n';
	for (int i = N - 1; i >= 0; i--)
	{
		cout << indices[i] + 1 << " " << (float)boys[indices[i]].d / boys[indices[i]].t << " " << boys[indices[i]].d << " " << boys[indices[i]].t << '\n';
	}
}