#include <iostream>

const int STICKS_IN_A_NUM = 7;

bool STICK_REPRESENTATIONS[][STICKS_IN_A_NUM] =
{ {1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1} };

bool EMPTY_NUM[STICKS_IN_A_NUM] = { 0,0,0,0,0,0,0 };

void deleteComb(bool** comb)
{
	int i = 0;
	while (comb[i] != EMPTY_NUM)
	{
		delete[] comb[i++];
	}

	delete[] comb;
}

void deleteMatrix(bool** matrix, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete matrix[i];
	}
	delete[] matrix;
}

bool* copy(const bool* sN)
{
	bool* newSN = new bool[STICKS_IN_A_NUM];

	for (int i = 0; i < STICKS_IN_A_NUM; i++)
	{
		newSN[i] = sN[i];
	}

	return newSN;
}

bool equal(const bool* r1, const bool* r2)
{
	for (int i = 0; i < STICKS_IN_A_NUM; i++)
	{
		if (r1[i] != r2[i])
		{
			return false;
		}
	}
	return true;
}

bool isValidRepresentation(const bool* nR)
{
	for (int i = 0; i < 10; i++)
	{
		if (equal(STICK_REPRESENTATIONS[i], nR))
		{
			return true;
		}
	}

	return false;
}

bool** getAddStickCombinations(const bool* sN)
{
	bool** combinations = new bool* [10];
	int index = 0;
	for (int i = 0; i < STICKS_IN_A_NUM; i++)
	{
		if (!sN[i])
		{
			bool* temp = copy(sN);
			temp[i] = 1;
			if (isValidRepresentation(temp))
			{
				combinations[index++] = temp;
			}
		}
	}
	combinations[index] = EMPTY_NUM;

	return combinations;
}

bool** getRemoveStickCombinations(const bool* sN)
{
	bool** combinations = new bool* [10];
	int index = 0;
	for (int i = 0; i < STICKS_IN_A_NUM; i++)
	{
		if (sN[i])
		{
			bool* temp = copy(sN);
			temp[i] = 0;
			if (isValidRepresentation(temp))
			{
				combinations[index++] = temp;
			}
		}
	}
	combinations[index] = EMPTY_NUM;

	return combinations;
}

bool** getMoveStickCombinations(const bool* sN)
{
	bool** combinations = new bool* [10];
	int index = 0;

	for (int i = 0; i < STICKS_IN_A_NUM; i++)
	{
		for (int j = i + 1; j < STICKS_IN_A_NUM; j++)
		{
			if (sN[i] != sN[j])
			{
				bool* temp = copy(sN);
				bool keeper = temp[i];
				temp[i] = temp[j];
				temp[j] = keeper;
				if (isValidRepresentation(temp))
				{
					combinations[index++] = temp;
				}
			}

		}
	}
	combinations[index] = EMPTY_NUM;

	return combinations;
}

int getStickAsNum(const bool* sN)
{
	for (int i = 0; i < 10; i++)
	{
		if (equal(STICK_REPRESENTATIONS[i], sN))
		{
			return i;
		}
	}

	return -1;
}

char* toStr(const int n1, const int n2, const int result, char operation)
{
	char* newStr = new char[6];
	newStr[0] = n1 + '0';
	newStr[1] = operation;
	newStr[2] = n2 + '0';
	newStr[3] = '=';
	newStr[4] = result + '0';
	newStr[5] = '\0';

	return newStr;
}

char* checkStickSwitchCase(bool** equation, const char operation)
{
	for (int i = 0; i < 3; i++)
	{
		bool** removeStickComb = getRemoveStickCombinations(equation[i]);
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				continue;
			}

			bool** addStickComb = getAddStickCombinations(equation[j]);

			int rI = 0;
			while (removeStickComb[rI] != EMPTY_NUM)
			{
				int aI = 0;
				while (addStickComb[aI] != EMPTY_NUM)
				{
					int n1;
					int n2;
					int result;
					if (i == 0)
					{
						n1 = getStickAsNum(removeStickComb[rI]);
						if (j != 2)
						{
							n2 = getStickAsNum(addStickComb[aI]);
							result = getStickAsNum(equation[2]);
						}
						else
						{
							n2 = getStickAsNum(equation[1]);
							result = getStickAsNum(addStickComb[aI]);
						}
					}
					else if (i == 1)
					{
						n2 = getStickAsNum(removeStickComb[rI]);
						if (j != 2)
						{
							n1 = getStickAsNum(addStickComb[aI]);
							result = getStickAsNum(equation[2]);
						}
						else
						{
							n1 = getStickAsNum(equation[0]);
							result = getStickAsNum(addStickComb[aI]);
						}
					}
					else if (i == 2)
					{
						result = getStickAsNum(removeStickComb[rI]);
						if (j == 1)
						{
							n1 = getStickAsNum(addStickComb[aI]);
							n2 = getStickAsNum(equation[1]);
						}
						else
						{
							n2 = getStickAsNum(addStickComb[aI]);
							n1 = getStickAsNum(equation[0]);
						}
					}

					if (operation == '+' && n1 + n2 == result)
					{
						return  toStr(n1, n2, result, operation);
					}
					else if (operation == '-' && n1 - n2 == result)
					{
						return  toStr(n1, n2, result, operation);
					}

					aI++;
				}
				rI++;
			}

			deleteComb(addStickComb);
		}
		deleteComb(removeStickComb);
	}

	return nullptr;
}

char* checkSignSwitchCase(bool** equation)
{
	for (int i = 0; i < 3; i++)
	{
		bool** addStickComb = getAddStickCombinations(equation[i]);
		int aI = 0;
		while (addStickComb[aI] != EMPTY_NUM)
		{
			int n1;
			int n2;
			int result;

			if (i == 0)
			{
				n1 = getStickAsNum(addStickComb[aI]);
				n2 = getStickAsNum(equation[1]);
				result = getStickAsNum(equation[2]);
			}
			else if (i == 1)
			{
				n1 = getStickAsNum(equation[0]);
				n2 = getStickAsNum(addStickComb[aI]);
				result = getStickAsNum(equation[2]);
			}
			else if (i == 2)
			{
				n1 = getStickAsNum(equation[0]);
				n2 = getStickAsNum(equation[1]);
				result = getStickAsNum(addStickComb[aI]);
			}

			if (n1 - n2 == result)
			{
				return toStr(n1, n2, result, '-');
			}

			aI++;
		}

		deleteComb(addStickComb);
	}

	return nullptr;
}

char* checkInNumberSwitchCase(bool** equation, const char operation)
{
	for (int i = 0; i < 3; i++)
	{
		bool** moveStickComb = getMoveStickCombinations(equation[i]);
		int aI = 0;
		while (moveStickComb[aI] != EMPTY_NUM)
		{
			int n1;
			int n2;
			int result;

			if (i == 0)
			{
				n1 = getStickAsNum(moveStickComb[aI]);
				n2 = getStickAsNum(equation[1]);
				result = getStickAsNum(equation[2]);
			}
			else if (i == 1)
			{
				n1 = getStickAsNum(equation[0]);
				n2 = getStickAsNum(moveStickComb[aI]);
				result = getStickAsNum(equation[2]);
			}
			else if (i == 2)
			{
				n1 = getStickAsNum(equation[0]);
				n2 = getStickAsNum(equation[1]);
				result = getStickAsNum(moveStickComb[aI]);
			}

			if (operation == '+' && n1 + n2 == result)
			{
				return toStr(n1, n2, result, operation);
			}
			else if (operation == '-' && n1 - n2 == result)
			{
				return toStr(n1, n2, result, operation);
			}

			aI++;
		}

		deleteComb(moveStickComb);
	}

	return nullptr;
}

char* fixEquation(char* str)
{
	int n1 = str[0] - '0';
	char operation = str[1];
	char n2 = str[2] - '0';
	char result = str[4] - '0';

	bool* sN1 = STICK_REPRESENTATIONS[n1];
	bool* sN2 = STICK_REPRESENTATIONS[n2];
	bool* sR = STICK_REPRESENTATIONS[result];

	bool ** equation = new bool*[3];
	equation[0] = sN1;
	equation[1] = sN2;
	equation[2] = sR;

	char* fixedEquation = nullptr;

	fixedEquation = checkStickSwitchCase(equation, operation);

	if (fixedEquation == nullptr && operation == '+')
	{
		fixedEquation = checkSignSwitchCase(equation);
	}
	if (fixedEquation == nullptr)
	{
		fixedEquation = checkInNumberSwitchCase(equation, operation);
	}

	delete[] equation;

	return fixedEquation;
}

int main()
{
	char str[6];

	std::cin >> str;

	char* fixedEquation = fixEquation(str);
	if (fixedEquation == nullptr)
	{
		std::cout << "No";
	}
	else
	{
		for (int i = 0; i < 5; i++)
		{
			std::cout << fixedEquation[i];
		}
	}

	delete[] fixedEquation;
}

