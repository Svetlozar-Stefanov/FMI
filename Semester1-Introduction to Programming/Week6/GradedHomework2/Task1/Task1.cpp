/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 1
* @compiler VC
*
*/

#include <iostream>
#include <vector>

using namespace std;

bool hasAlteringBits(unsigned n)
{
	vector<int> bits = {};

	while (n > 0)
	{
		bits.push_back(n % 2);

		n /= 2;
	}

	bool hasAlteringBits = true;

	int cap = bits.size() - 1;
	for (int i = 0; i < cap; i++)
	{
		if (bits[i] == bits[i + 1])
		{
			hasAlteringBits = false;
			break;
		}
	}

	return hasAlteringBits;
}

int main()
{
	int n;
	if (!(cin >> n) || n < 0)
	{
		cout << "-1";
		return 1;
	}

	if (hasAlteringBits(n))
	{
		cout << "true";
	}
	else
	{
		cout<<"false";
	}

	return 0;
}
