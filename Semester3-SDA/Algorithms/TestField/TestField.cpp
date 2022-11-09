#pragma once
#include <iostream>
#include "Algorithms/SortingAlgorithms.h"
#include "Algorithms/SearchingAlgorithms.h"
//#include "DataStructures/LinkedList.h"
#include "DataStructures/BinarySearchTree.h"

int main()
{
 //   //vector<int> arr = { 5, -3, 4, -5, 2, 1, -4, 0, 3, -2, -1 };
	////vector<int> arr = { 132, 312, 52342, 5436, 3543, 3234, 6234, 745, 3123 };
	///*List<int> list;
	//list.push_back(1);
	//list.push_back(2);
	//list.push_back(3);
	//list.push_back(4);
	//list.push_back(5);
	//list.push_back(6);
	//list.push_back(7);*/

	//BinarySearchTree tree;
	//tree.insert(5);
	//tree.insert(6);
	//tree.insert(4);
	//tree.insert(10);
	//tree.insert(7);
	//tree.insert(12);
	//tree.insert(9);

	//tree.inorderPrint();
	//cout << '\n';

	//tree.remove(6);
	//tree.inorderPrint();
	//cout << '\n';

	//tree.remove(10);
	//tree.inorderPrint();
	//cout << '\n';

	//tree.remove(9);
	//tree.inorderPrint();
	//cout << '\n';

	vector<int> v = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15 };
	cout << longestIncreasingSubsequence(v) << '\n';
 }