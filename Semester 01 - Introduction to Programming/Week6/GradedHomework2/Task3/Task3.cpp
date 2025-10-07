/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 3
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int firstNumAfterTarget(unsigned n, const unsigned target)
{
	while (n < target)
	{
		n *= 2;
	}

	return n;
}

int shortestPath(unsigned startValue, const unsigned target)
{
	unsigned steps = 0;

	while (startValue != target)
	{

		while (startValue > target)
		{
			startValue--;
			steps++;
		}

		if (startValue < target)
		{
			unsigned multipliedNum = firstNumAfterTarget(startValue, target);

			unsigned subtractedNum = startValue;
			if (startValue > 1)
			{
				subtractedNum--;
			}
			subtractedNum = firstNumAfterTarget(subtractedNum, target);

			if (multipliedNum - target <= subtractedNum - target)
			{
				startValue *= 2;
				steps++;
			}
			else if (multipliedNum - target > subtractedNum - target)
			{
				startValue -= 1;
				steps++;
			}
		}
	}

	return steps;
}

int main()
{
	int n;
	int target;

	if (!(cin >> n)
		|| !(cin >> target)
		|| n < 0 || target < 0
		|| (n == 0 && target > 0))
	{
		cout << "-1";
		return 1;
	}

	cout << shortestPath(n, target);

	return 0;
}
