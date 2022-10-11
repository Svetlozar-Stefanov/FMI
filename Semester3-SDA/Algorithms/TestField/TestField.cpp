#include <iostream>
#include "Algorithms/SortingAlgorithms.h"

void print(const vector<int> &arr) {
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

int main()
{
    //vector<int> arr = { 5, -3, 4, -5, 2, 1, -4, 0, 3, -2, -1 };
	vector<int> arr = { 132, 312, 52342, 5436, 3543, 3234, 6234, 745, 3123 };

    
	radixSort(arr);

	print(arr);
}