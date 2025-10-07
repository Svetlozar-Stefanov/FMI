#include <iostream>

int* countLetters(const int arr1[], const int arr2[], const int size)
{
	if (arr1 == nullptr || arr2 == nullptr)
	{
		return nullptr;
	}

	int res[2] = {0};

	for (int i = 0; i < size; i++)
	{
		char ch = (char)(arr1[i] + arr2[i]);
		if (ch >= 'A' && ch <= 'Z')
		{
			res[0]++;
		}
		else if (ch >= 'a' && ch <= 'z')
		{
			res[1]++;
		}
	}

	return res;
}

int main()
{
	int a[] = { 3, 5, 11, 2, 9 };
	int b[] = { 1, 4, 32, 71, 5 };

	int* res = countLetters(a,b, 5);
	std::cout << res[0] << " " << res[1];
}