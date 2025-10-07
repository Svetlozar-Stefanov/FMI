#include <iostream>

using namespace std;

int numberOfChanges(char* arr, int len) {

	int count = 0;
	for (int i = 0; i < len - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			count++;
		}
	}

	return count;
}

int main()
{
	int Q = 0;
	cin >> Q;

	int len = 0;
	char* list;

	for (int i = 0; i < Q; i++)
	{
		cin >> len;
		list = new char[len + 1];
		cin >> list;

		cout << numberOfChanges(list, len) << '\n';
		delete[] list;
	}

	return 0;
}