#include <iostream>

bool isPalindromeInRange(const int arr[], const int from, const int to)
{	
	for (int i = 0; i < (to - from) / 2; i++)
	{
		if (arr[i + from] != arr[to - i - 1])
		{
			return false;
		}
	}

	return true;
}

bool helper(const int arr[], const int from, const int to, const int step)
{
	if (isPalindromeInRange(arr, from, to))
	{
		return true;
	}
	if (step <= 0)
	{
		return false;
	}

	return helper(arr, from + 1, to, step - 1) || helper(arr, from, to - 1, step - 1);
}

bool canBecomeAPalindrome(const int arr[], const int size, const int steps) 
{
	return helper(arr, 0, size, steps);
}

int main()
{
	int arr[] = { 7, 1, 2, 1, 4, 2, 3};

	std::cout << canBecomeAPalindrome(arr, 7, 3);
}