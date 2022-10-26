#pragma once
#include <iostream>
#include "Algorithms/SortingAlgorithms.h"
#include "Algorithms/SearchingAlgorithms.h"
#include "DataStructures/LinkedList.h"

void print_arr(vector<int> &arr) {
	for (uint64_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
	cout << '\n';
}

typedef struct {
	unsigned int  age : 4;
	unsigned char gender : 1;
	unsigned int  size : 2;
}child_t;

int main()
{
    //vector<int> arr = { 5, -3, 4, -5, 2, 1, -4, 0, 3, -2, -1 };
	//vector<int> arr = { 132, 312, 52342, 5436, 3543, 3234, 6234, 745, 3123 };
	List<int> list;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	list.push_back(6);
	list.push_back(7);

	list.reverse_list();

	list.print();

	cout << sizeof(child_t);
}