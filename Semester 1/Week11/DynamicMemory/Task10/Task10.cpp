#include <iostream>

using namespace std;

int** createMatrix(const int rows, const int colSizes[])
{
	int** matrix = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		int cols = colSizes[i];
		int* row = new int[cols];
		for (int i = 0; i < cols; i++)
		{
			cin >> row[i];
		}

		matrix[i] = row;
	}

	return matrix;
}

void destroyMatrix(int** matrix, const int rows, const int colSizes[])
{
	for (int i = 0; i < rows; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int main()
{
	int rows;
	cin >> rows;

	int* cols = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		cin >> cols[i];
	}

	int** matrix = createMatrix(rows, cols);


	for (int i = 0; i < rows; i++)
	{
		int sum = 0;
		for (int j = 0; j < cols[i]; j++)
		{
			sum += matrix[i][j];
		}

		cout << sum << ' ';
	}

	destroyMatrix(matrix, rows, cols);
}