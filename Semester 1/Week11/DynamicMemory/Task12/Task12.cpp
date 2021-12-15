#include <iostream>

using namespace std;

int** createMatrix(const int rows, const int cols)
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		int* row = new int[cols];
		for (int i = 0; i < cols; i++)
		{
			cin >> row[i];
		}

		matrix[i] = row;
	}

	return matrix;
}

void destroyMatrix(int** matrix, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

bool isSymetrical(int** matrix, const int rows, const int cols) 
{
	bool symetrical = true;

	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j < cols; j++)
		{
			if (matrix[i][j] != matrix[j][i])
			{
				symetrical = false;
				return symetrical;
			}
		}
	}

	return symetrical;
}

int main()
{
	int rows;
	int cols;

	cin >> rows;
	cin >> cols;

	int** matrix = createMatrix(rows, cols);

	cout << isSymetrical(matrix, rows, cols);

	destroyMatrix(matrix, rows, cols);
}