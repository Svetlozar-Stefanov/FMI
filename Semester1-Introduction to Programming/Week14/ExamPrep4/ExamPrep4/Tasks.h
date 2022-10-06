#pragma once

// Task1
struct Point
{
	double x;
	double y;
};

bool CheckRectangular(const Point& A, const Point& B, const Point& C)
{
	double AB = (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
	double AC = (A.x - C.x) * (A.x - C.x) + (A.y - C.y) * (A.y - C.y);
	double BC = (B.x - C.x) * (B.x - C.x) + (B.y - C.y) * (B.y - C.y);
	 
	if (AB + AC < BC || AB + BC < AC || AC + BC < AB)
	{
		return false;
	}

	if (AB * AB + AC * AC == BC*BC 
		|| AB * AB + BC * BC  == AC * AC
		|| AC * AC + BC * BC == AB * AB)
	{
		return true;
	}
	
	return false;
}

// Task2
const char EQUATION_TEMPLATE[] = "à*õ^2+b*x+c=0";

int strleng(const char * str) 
{
	if (str == nullptr)
	{
		return -1;
	}

	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}

	return i;
}

bool isValid(const char* equ)
{
	int sizeEqu = strleng(equ);
	int sizeTemp = strleng(EQUATION_TEMPLATE);

	if (equ == nullptr || sizeEqu != sizeTemp)
	{
		return false;
	}

	for (int i = 0; i < sizeEqu; i++)
	{
		if (i == 0 || i == 6 || i == 10)
		{
			if (equ[i] < '0' || equ[i] > '9')
			{
				return false;
			}
			
			continue;
		}

		if (equ[i] != EQUATION_TEMPLATE[i])
		{
			return false;
		}
	}

	return true;
}

double max(const double a, const double b) 
{
	int eps = 100000;

	if (a*eps >= b*eps)
	{
		return a;
	}

	return b;
}

double Solve(const char * equ) 
{
	if (!isValid(equ))
	{
		return -1;
	}

	int a = equ[0] - '0';
	int b = equ[6] - '0';
	int c = equ[10] - '0';

	int D = b * b - 4 * a * c;

	double x1 = (-b + sqrt(D)) / 2 * a;
	double x2 = (-b - sqrt(D)) / 2 * a;

	return max(x1, x2);
}

// Task3
void Revert(long &num) 
{
	int result = 0;

	while (num != 0)
	{
		result += num % 10;
		result *= 10;
		num /= 10;
	}
	result /= 10;

	num = result;
}

// Task4
int GetWord(const char str[]) 
{
	if (str == nullptr)
	{
		return -1;
	}

	int size = strleng(str);

	int i = 0;
	int maxWord = 0;
	int index = 0;

	while (str[i] != '\0')
	{
		while ((str[i] == ' ' || str[i] == '\t')
			&& i < size)
		{
			i++;
		}

		int tempSize = 0;
		int tempIndex = i;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0'
			&& i < size)
		{
			i++;
			tempSize++;
		}

		if (tempSize > maxWord)
		{
			maxWord = tempSize;
			index = tempIndex;
		}
	}
	
	return index;
}

// Task5

int digitsCount(int num) 
{
	int counter = 0;
	do
	{
		counter++;
		num /= 10;
	} while (num != 0);

	return counter;
}

int* getDigits(int num) 
{
	int size = digitsCount(num);
	int* digits = new int[size];

	for (int i = 0; i < size; i++)
	{
		digits[i] = num % 10;
		num /= 10;
	}

	return digits;
}

void sort(int arr[], const int size) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] < arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int Find(const long N, const int n)
{
	if (N <= 0 || n >= 8)
	{
		return -1;
	}
	int size = digitsCount(N);

	if (n > size)
	{
		return -1;
	}

	int* digits = getDigits(N);

	sort(digits, size);

	int biggestNum = 0;
	for (int i = 0; i < n; i++)
	{
		biggestNum += digits[i];
		biggestNum *= 10;
	}
	biggestNum /= 10;

	delete[] digits;

	return biggestNum;
}