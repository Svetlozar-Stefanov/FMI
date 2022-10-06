#include <iostream>

int** mergeArrays(int * arr1, int * arr2, const int m) 
{
	int** matrix = new int*[2];
	matrix[0] = arr1;
	matrix[1] = arr2;
	
	return matrix;
}

int main()
{
	int arr1[] = { 3, 5, 11, 2, 9 };
	int arr2[] = { 1, 4, 32, 71, 5 };

	int** matrix = mergeArrays(arr1, arr2, 5);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << '\n';
	}

	delete[] matrix;
}