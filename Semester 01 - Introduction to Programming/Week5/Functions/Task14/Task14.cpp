#include <iostream>

using namespace std;

int getSmallestNumber(const int n, const int numbers[])
{
	int smallestNum = INT_MAX;

	for (int i = 0; i < n; i++)
	{
		if (numbers[i] < smallestNum)
		{
			smallestNum = numbers[i];
		}
	}

	return smallestNum;
}

int getBiggestNumber(const int n, const int numbers[])
{
	int biggestNum = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		if (numbers[i] > biggestNum)
		{
			biggestNum = numbers[i];
		}
	}

	return biggestNum;
}

int NOD(const int n, const int numbers[]) 
{
	int smallestNumber = getSmallestNumber(n, numbers);

	for (int i = 2; i <= smallestNumber; i++)
	{
		bool isNod = true;
		for (int j = 0; j < n; j++)
		{
			if (numbers[j] % i != 0)
			{
				isNod = false;
				break;
			}
		}
		if (isNod)
		{
			return i;
		}
	}

	return 1;
}

int NOK(const int n, const int numbers[]) 
{
	int d = getBiggestNumber(n, numbers);

	bool isNok = false;

	while (!isNok)
	{
		isNok = true;

		for (int i = 0; i < n; i++)
		{
			if (d % numbers[i] != 0)
			{
				isNok = false;
				d++;
				break;
			}
		}
	}

	return d;
}

int main()
{
	int n;

	cin >> n;

	int *numbers = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> numbers[i];
	}
	
	cout << NOD(n, numbers)<<endl;
	cout << NOK(n, numbers);
}