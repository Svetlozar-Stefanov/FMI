#include <iostream>

const int EPS = 1000000;
const int DEG = 4;

double** createMatrix(const unsigned rows, const unsigned cols)
{
	double** matrix = new double* [rows];
	for (int i = 0; i < rows; i++)
	{
		matrix[i] = new double[cols];
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = 0;
		}
	}

	return matrix;
}

void deleteMatrix(char** matrix, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete matrix[i];
	}
	delete[] matrix;
}

bool isBigger(const double n1, const double n2)
{
	return (int)(n1 * EPS) > (int)(n2 * EPS);
}

bool equal(const double n1, const double n2)
{
	return (int)(n1 * EPS) == (int)(n2 * EPS);
}

double absolute(const double n)
{
	return n < 0 ? -n : n;
}

void moveMinUpAtRowAndCol(const int n, double**& a, const int row, const int col)
{
	if (a == nullptr)
	{
		return;
	}

	int minI = row;
	for (int i = row + 1; i < n; i++)
	{
		if (equal(a[minI][col], 0))
		{
			minI = i;
			continue;
		}

		if (isBigger(1, absolute(a[minI][col])))
		{
			minI = i;
			continue;
		}

		if (!equal(a[i][col], 0)
			&& !isBigger(1, absolute(a[i][col]))
			&& (isBigger(absolute(a[minI][col]), absolute(a[i][col]))))
		{
			minI = i;
		}
	}

	double* temp = a[row];
	a[row] = a[minI];
	a[minI] = temp;
}

int min(const int n1, const int n2)
{
	return n1 < n2 ? n1 : n2;
}

int max(const int n1, const int n2)
{
	return n1 > n2 ? n1 : n2;
}

int GCD(const int n1, const int n2)
{
	if (equal(n2, 0))
	{
		return n1;
	}

	GCD(n2, n1 % n2);
}

int arrGCD(const double* arr, const int size)
{
	if (arr == nullptr || size <= 0)
	{
		return -1;
	}

	if (size == 1)
	{
		return arr[0];
	}

	int tempGCD = GCD(max(arr[0], arr[1]), min(arr[0], arr[1]));
	for (int i = 2; i < size; i++)
	{
		tempGCD = GCD(max(tempGCD, arr[i]), min(tempGCD, arr[i]));
	}

	return tempGCD;
}

bool hasOnlyWholeNumbers(const double* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		if (!equal(arr[i], (int)arr[i]))
		{
			return false;
		}
	}

	return true;
}

void simplify(double**& a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		if (hasOnlyWholeNumbers(a[i], n))
		{
			int divisor = arrGCD(a[i], n);
			if (divisor == 0
				|| divisor == -1
				|| divisor == 1)
			{
				continue;
			}
			for (int j = 0; j < DEG; j++)
			{
				a[i][j] /= divisor;
			}
		}
	}
}

//int rang(double** a, const int n)
//{
//	int vectorRang = n;
//	for (int i = 0; i < n; i++)
//	{
//		bool zeroRow = true;
//		for (int j = 0; j < DEG; j++)
//		{
//			if (!equal(a[i][j], 0))
//			{
//				zeroRow = false;
//				break;
//			}
//		}
//		if (zeroRow)
//		{
//			vectorRang--;
//		}
//	}
//
//	return vectorRang;
//}

int getRang(double** a)
{
	int i = 0;
	int count = 0;

	bool zeroRow;
	while (true)
	{
		zeroRow = true;

		for (int j = 0; j < DEG; j++)
		{
			if (a[i][j] != 0)
			{
				zeroRow = false;
			}
		}

		if (zeroRow)
		{
			break;
		}

		count++;
		i++;
	}

	return count;
}

void getBasis(double** a, const int n)
{
	for (int i = 0; i < n; i++)
	{
		simplify(a, n);
		moveMinUpAtRowAndCol(n, a, i, i);
		double sub = a[i][i];
		if (sub == 0)
		{
			continue;
		}

		for (int j = i + 1; j < n; j++)
		{
			double mult = (-1 * a[j][i]) / sub;
			for (int l = 0; l < DEG; l++)
			{
				a[j][l] += a[i][l] * mult;
			}
		}
	}

	simplify(a, n);
}

double** getEquationBasis(double** a, const int n)
{
	int basisSize = DEG - getRang(a);

	double** equationBasis = createMatrix(basisSize + 1, DEG);

	int* p = new int[basisSize];
	for (int i = 0; i < basisSize; i++)
	{
		p[i] = 0;
	}

	for (int i = 0; i < basisSize; i++)
	{
		p[i]++;

		for (int j = 0; j < basisSize; j++)
		{
			equationBasis[i][DEG - j - 1] = p[j];
		}

		for (int j = DEG - basisSize - 1; j >= 0; j--)
		{
			for (int l = j + 1; l < DEG; l++)
			{
				equationBasis[i][j] -= a[j][l] * equationBasis[i][l];
			}

			if (a[j][j] != 0)
			{
				equationBasis[i][j] /= a[j][j];
				for (int l = 0; l < DEG; l++)
				{
					equationBasis[i][l] *= a[j][j];
				}
			}
		}

		for (int i = 0; i < basisSize; i++)
		{
			for (int j = 0; j < DEG; j++)
			{
				std::cout << equationBasis[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << std::endl;

		p[i]--;
	}

	delete[] p;

	return equationBasis;
}

double** getSumBasis(double** a, double** b, const int n, const int m)
{
	getBasis(a, n);

	getBasis(b, m);

	double** equationBasis = getEquationBasis(b, m);

	int rangA = getRang(a);
	int rangE = getRang(equationBasis);

	double** sumBasis = createMatrix(rangA + rangE + 1, DEG);
	for (int i = 0; i < rangA; i++)
	{
		for (int j = 0; j < DEG; j++)
		{
			sumBasis[i][j] = a[i][j];
		}
	}
	for (int i = rangA; i < rangA + rangE; i++)
	{
		for (int j = 0; j < DEG; j++)
		{
			sumBasis[i][j] = equationBasis[i - rangA][j];
		}
	}

	for (int i = 0; i < rangA + rangE; i++)
	{
		for (int j = 0; j < DEG; j++)
		{
			std::cout << sumBasis[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;

	getBasis(sumBasis, rangA + rangE);

	return sumBasis;
}

int main()
{
	int n = 4;
	int m = 2;

	double matrixA[][DEG] =
	{
		{2,8,-3,14},
		{-1,2,3,5},
		{-1,14,6,29 },
		{0, 12, 3, 24}
	};

	double** a = createMatrix(n+1, DEG);
	for (int i = 0; i < n; i++)
	{
		a[i] = matrixA[i];
	}

	double matrixB[][DEG] =
	{
		{0,1,1,0},
		{10,7,0,-8}
	};

	double** b = createMatrix(m+1, DEG);
	for (int i = 0; i < m; i++)
	{
		b[i] = matrixB[i];
	}

	double** sumBasis = getSumBasis(a, b, n, m);

	for (int i = 0; i < getRang(sumBasis); i++)
	{
		for (int j = 0; j < DEG; j++)
		{
			std::cout << sumBasis[i][j] << " ";
		}
		std::cout << std::endl;
	}
}