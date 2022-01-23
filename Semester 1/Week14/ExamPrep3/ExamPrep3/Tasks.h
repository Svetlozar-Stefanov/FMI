#pragma once
// Task1
int* mergeAndSort(const int* arr1, const int* arr2, const int size1, const int size2)
{
	if (arr1 == nullptr || arr2 == nullptr)
	{
		return nullptr;
	}

	int i1 = 0;
	int i2 = 0;

	int* arr = new int[size1 + size2];
	for (int i = 0; i < size1 + size2; i++)
	{
		if ((i1 < size1 && arr1[i1] <= arr2[i2]) || i2 >= size2)
		{
			arr[i] = arr1[i1++];
		}
		else if ((i2 < size2 && arr1[i1] > arr2[i2]) || i1 >= size1)
		{
			arr[i] = arr2[i2++];
		}
	}

	return arr;
}

// Task2
struct Line
{
	double X1;
	double X2;
	double Y1;
	double Y2;
};

double commonLength(const Line ln1, const Line ln2)
{
	if (ln1.Y1 == ln1.Y2 && ln2.Y1 == ln2.Y2 && ln1.Y1 == ln2.Y2)
	{
		if (ln1.X1 <= ln2.X1 && ln1.X2 <= ln2.X2)
		{
			return abs(ln2.X1 - ln1.X2);
		}
		if (ln1.X1 <= ln2.X1 && ln1.X2 >= ln2.X2)
		{
			return abs(ln2.X1 - ln2.X2);
		}
		if (ln1.X1 >= ln2.X1 && ln1.X2 >= ln2.X2)
		{
			return abs(ln1.X1 - ln2.X2);
		}
		return commonLength(ln2, ln1);
	}
	else if (ln1.X1 == ln1.X2 && ln2.X1 == ln2.X2 && ln1.X1 == ln2.X1)
	{
		if (ln1.Y1 <= ln2.Y1 && ln1.Y2 <= ln2.Y2)
		{
			return abs(ln2.Y1 - ln1.Y2);
		}
		if (ln1.Y1 <= ln2.Y1 && ln1.Y2 >= ln2.Y2)
		{
			return abs(ln2.Y1 - ln2.Y2);
		}
		if (ln1.Y1 >= ln2.Y1 && ln1.Y2 >= ln2.Y2)
		{
			return abs(ln1.Y1 - ln2.Y2);
		}

		return commonLength(ln2, ln1);
	}

	return -1;
}

// Task3
void printRectangle(const int length, const int width, const char ch)
{
	for (int i = 0; i < (25 - length) / 2; i++)
	{
		std::cout << std::endl;
	}
	for (int i = 0; i < length; i++)
	{
		for (int i = 0; i < (80 - width) / 2; i++)
		{
			std::cout << " ";
		}
		for (int i = 0; i < width; i++)
		{
			std::cout << ch;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < (25 - length) / 2; i++)
	{
		std::cout << std::endl;
	}
}

// Task4 
double upperTriangleSum(int** matrix, const int n)
{
	if (matrix == nullptr)
	{
		return -1;
	}

	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			sum += matrix[j][i];
		}
	}

	return sum;
}

// Task5
int** createMatrix(const int n)
{
	int** matrix = new int* [n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}

	return matrix;
}

int** transposed(const int matrix[4][4], const int n)
{
	if (matrix == nullptr)
	{
		return nullptr;
	}

	int** trMatrix = createMatrix(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			trMatrix[i][j] = matrix[j][i];
		}
	}

	return trMatrix;
}

// Task6
double helper(const double x, const double a, const double eps)
{
	double newX = (x + a / x) / 2;

	if (abs(newX - x) < eps)
	{
		return newX;
	}

	return helper(newX, a, eps);
}

double sqrt_a(const double a, const double eps)
{
	if (a < 0)
	{
		return 0;
	}

	return helper(a, a, eps);
}

// Task7
int strleng(const char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}

void revert(char str[])
{
	if (str == nullptr)
	{
		return;
	}
	int size = strleng(str);
	for (int i = 0; i < size; i++)
	{
		if ('a' <= str[i] && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if ('A' <= str[i] && str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
}

// Task8
bool checkDate(const char str[])
{
	if (str == nullptr)
	{
		return false;
	}
	int size = strleng(str);

	if (size != 5)
	{
		return false;
	}

	int days = 0;
	for (int i = 0; i < 2; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
		days += str[i] - '0';
		days *= 10;
	}
	days /= 10;

	if (str[2] != '.')
	{
		return false;
	}

	int months = 0;
	for (int i = 3; i < 5; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return false;
		}
		months += str[i] - '0';
		months *= 10;
	}
	months /= 10;

	if (months <= 0 || months > 12)
	{
		return false;
	}

	if ((months == 1 
		|| months == 3
		|| months == 5
		|| months == 7
		|| months == 8
		|| months == 10
		|| months == 12) 
		&& (days <= 0 || days > 31))
	{
		return false;
	}

	if ((months == 4
		|| months == 6
		|| months == 9
		|| months == 11)
		&& (days <= 0 || days > 30))
	{
		return false;
	}

	if ((months == 2)
		&& (days <= 0 || days > 28))
	{
		return false;
	}

	return true;
}

// Task9
int digitsCount(long num) 
{
	int count = 0;
	do
	{
		count++;
		num /= 10;
	} while (num != 0);

	return count;
}

int* digits(long num)
{
	int count = digitsCount(num);

	int* d = new int[count];
	for (int i = count - 1; i >= 0; i--)
	{
		d[i] = num % 10;
		num /= 10;
	}

	return d;
}

int digitPos(long num, const int k) 
{
	int count = digitsCount(num);
	if (k < 1 || k > count)
	{
		return -1;
	}

	int* d = digits(num);

	int n = d[k - 1];

	delete[] d;

	return n;
}

// Task10
bool doExist(const char * str, const char * word) 
{
	if (str == nullptr || word == nullptr)
	{
		return false;
	}

	int sizeS = strleng(str);
	int sizeW = strleng(word);

	int index = 0;
	for (int i = 0; i < sizeS; i++)
	{
		if (str[i] == word[index])
		{
			index++;
		}
		else
		{
			index = 0;
		}

		if ((str[i+1] == ' ' || str[i+1] == '\0') 
			&& index == sizeW)
		{
			return true;
		}
	}

	return false;
}

