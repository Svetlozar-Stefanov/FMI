#include <iostream>

int** createMatrix(const int rows, const int cols) 
{
    int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new int[cols];
	}

	return matrix;
}

void deleteMatrix(int ** matrix, const int rows) 
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int ** transposeMatrix(int ** matrix, const int rows, const int cols) 
{
	int** transposedMatrix = createMatrix(cols,rows);
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			transposedMatrix[j][i] = matrix[i][j];
		}
	}

	return transposedMatrix;
}

int main()
{
	int arr[][4] =
	{
		{1,2,3,4},
		{1,2,3,4}
	};

	int** matrix = createMatrix(2,4);

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			matrix[i][j] = arr[i][j];
		}
	}

	int ** tr = transposeMatrix(matrix,2,4);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			std::cout << tr[i][j] << " ";
		}
		std::cout << '\n';
	}
}