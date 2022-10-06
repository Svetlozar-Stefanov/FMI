/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int INVALID_SIZE_EXIT = -2;
const int NO_REP_EXIT = -1;

int longestDist(const int arr[], const int arrSize) 
{
	if (arrSize <= 1 || arrSize > 100)
	{
		return INVALID_SIZE_EXIT;
	}

	int maxDist = INT_MIN;
	int index = NO_REP_EXIT;

	for (int i = 0; i < arrSize; i++)
	{
		int current = arr[i];
		for (int j = arrSize - 1; j > i; j--)
		{
			if (current == arr[j] 
				&& maxDist < j - i)
			{
				maxDist = j - i;
				index = i;
			}
		}
	}

	return index;
}

int main()
{
	int N;
	cin >> N;

	int arr[100];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	cout << longestDist(arr, N);
}
