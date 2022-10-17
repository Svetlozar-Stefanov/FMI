#include <iostream>
#include "Algorithms/SortingAlgorithms.h"
#include "Algorithms/SearchingAlgorithms.h"

void print(vector<int> &arr) {
	for (uint64_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main()
{
    vector<int> arr = { 5, -3, 4, -5, 2, 1, -4, 0, 3, -2, -1 };
	//vector<int> arr = { 132, 312, 52342, 5436, 3543, 3234, 6234, 745, 3123 };

	quicksort(arr);

	cout << quickselectNthNum(arr, 11);
}