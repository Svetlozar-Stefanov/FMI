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

int main()
{
	int rows;
	int cols;

	cin >> rows;
	cin >> cols;

	int** matrix = createMatrix(rows, cols);


	bool hasNegative = false;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] < 0)
			{
				hasNegative = true;
				break;
			}
		}

		if (hasNegative)
		{
			break;
		}
	}

	cout << hasNegative;

	destroyMatrix(matrix, rows, cols);
}