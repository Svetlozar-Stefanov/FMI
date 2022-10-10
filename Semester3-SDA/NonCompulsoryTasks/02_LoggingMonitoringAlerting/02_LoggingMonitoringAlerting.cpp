#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> entries;
int indecies[200000];

void swap(int* arr, int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

bool isBiggerTime(vector<int>& t1, vector<int>& t2) {
	bool isBigger = false;
	for (size_t i = 0; i < t1.size(); i++)
	{
		if (t1[i] == t2[i])
		{
			continue;
		}
		else if (t1[i] > t2[i])
		{
			isBigger = true;
			break;
		}
		else
		{
			break;
		}
	}

	return isBigger;
}

vector<int> parseTime(string& hour, string& date)
{
	int hours = stoi(hour.substr(0, 2));
	int minutes = stoi(hour.substr(3, 2));
	int seconds = stoi(hour.substr(6, 2));

	int day = stoi(date.substr(0, 2));
	int month = stoi(date.substr(3, 2));
	int year = stoi(date.substr(6, 4));

	vector<int> res;
	res.push_back(year);
	res.push_back(month);
	res.push_back(day);
	res.push_back(hours);
	res.push_back(minutes);
	res.push_back(seconds);

	return res;
}

void merge(int * arr, int l, int m, int r) {

	int s1 = m - l + 1;
	int* arr1 = new int[s1];
	int i1 = 0;
	for (int i = l; i <= m; i++)
	{
		arr1[i1++] = arr[i];
	}

	int s2 = r - m;
	int* arr2 = new int[s2];
	int i2 = 0;
	for (int i = m + 1; i <= r; i++)
	{
		arr2[i2++] = arr[i];
	}

	i1 = 0;
	i2 = 0;
	int k = l;

	while (i1 < s1 && i2 < s2)
	{
		if (!isBiggerTime(entries[arr1[i1]], entries[arr2[i2]]))
		{
			arr[k++] = arr1[i1++];
		}
		else
		{
			arr[k++] = arr2[i2++];
		}
	}

	while (i1 < s1)
	{
		arr[k++] = arr1[i1++];
	}

	while (i2 < s2)
	{
		arr[k++] = arr2[i2++];
	}

	delete[] arr1;
	delete[] arr2;
}

void mergeSortHelper(int* arr, int l, int r) {
	if (l >= r)
	{
		return;
	}

	int middle = l + ((r - l) / 2);

	mergeSortHelper(arr, l, middle);
	mergeSortHelper(arr, middle + 1, r);
	merge(arr, l, middle, r);
}

void mergeSort(int* arr, int size) {
	mergeSortHelper(arr, 0, size - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 100000;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string hour;
		cin >> hour;

		string date;
		cin >> date;

		entries.push_back(parseTime(hour, date));
		indecies[i] = i;
	}

	mergeSort(indecies, N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << entries[indecies[i]][j] << ' ';
		}
		cout << "\n";
	}

	/*for (int i = 0; i < N; i++)
	{
		cout << indecies[i] + 1;
		cout << "\n";
	}*/
}
