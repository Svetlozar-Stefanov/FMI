#pragma once
#include <iostream>
#include "Algorithms/SortingAlgorithms.h"
#include "Algorithms/SearchingAlgorithms.h"
//#include "DataStructures/LinkedList.h"
#include "DataStructures/BinarySearchTree.h"

int main()
{
	vector<int> v = { 5, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	BSTree tree;
	for (int i = 0; i < v.size(); i++)
	{
		tree.insert(v[i]);
	}

	tree.remove(10);
	tree.remove(5);

	tree.lrt_print();
 }