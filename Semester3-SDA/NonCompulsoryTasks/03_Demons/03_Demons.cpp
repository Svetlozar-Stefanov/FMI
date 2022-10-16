#include <iostream>
#include <vector>

using namespace std;

struct Demon {
	uint64_t attack;
	uint64_t deffence;
};

bool operator>=(const Demon& d1, const Demon& d2)
{
	return d1.attack > d2.attack || d1.attack == d2.attack && d1.deffence > d2.deffence;
}

bool operator>(const Demon& d1, const Demon& d2)
{
	return d1.attack > d2.attack && d1.deffence > d2.deffence;
}

void swap(vector<Demon>& arr, int i1, int i2)
{
	Demon temp = arr[i1];
	arr[i1] = arr[i2];
	arr[i2] = temp;
}

int partition(vector<Demon>& arr, int l, int r)
{
	Demon pivot = arr[r];

	int s = l;
	for (int i = l; i < r; i++)
	{
		if (arr[i] > pivot)
		{
			swap(arr, s, i);
			s++;
		}
	}
	swap(arr, s, r);

	return s;
}

void quicksortHelper(vector<Demon>& arr, int l, int r) {
	if (l >= r)
	{
		return;
	}

	int m = partition(arr, l, r);

	quicksortHelper(arr, l, m - 1);
	quicksortHelper(arr, m + 1, r);
}

void quicksort(vector<Demon>& arr) {
	quicksortHelper(arr, 0, arr.size() - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<Demon> demons(N);
	for (int i = 0; i < N; i++)
	{
		cin >> demons[i].attack;
		cin >> demons[i].deffence;
	}

	quicksort(demons);

	for (int i = 0; i < N; i++)
	{
		cout << demons[i].attack << " " << demons[i].deffence << '\n';
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		Demon player = demons[i];
		int temp = 1;
		for (int j = 0; j < N; j++)
		{
			if (player > demons[j])
			{
				player = demons[j];
				temp++;
			}
		}
		if (max < temp)
		{
			max = temp;
		}
	}

	cout << max;
}