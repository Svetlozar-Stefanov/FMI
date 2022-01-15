/**
*
* Solution to homework assignment 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 3
* @compiler VC
*
*/

#include <iostream>

const int STICKS_IN_A_NUM = 7;

const int EQUATION_SIZE = 3;
const int N1_INDX = 0;
const int N2_INDX = 1;
const int RES_INDX = 2;

bool STICK_REPRESENTATIONS[][STICKS_IN_A_NUM] =
{ 
	{1,1,1,1,1,1,0},
	{0,1,1,0,0,0,0},
	{1,1,0,1,1,0,1},
	{1,1,1,1,0,0,1},
	{0,1,1,0,0,1,1},
	{1,0,1,1,0,1,1},
	{1,0,1,1,1,1,1},
	{1,1,1,0,0,0,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1} 
};

bool EMPTY_NUM[STICKS_IN_A_NUM] = { 0,0,0,0,0,0,0 };

int strleng(const char* str)
{
	if (str == nullptr)
	{
		return -1;
	}

	unsigned count = 0;
	unsigned i = 0;
	while (str[i] != '\0')
	{
		count++;
		i++;
	}

	return count;
}

void deleteComb(bool** comb)
{
	int i = 0;
	while (comb[i] != EMPTY_NUM)
	{
		delete[] comb[i++];
	}

	delete[] comb;
}

void deleteEquations(char** equa)
{
	int i = 0;
	while (equa[i][0] != '\0')
	{
		delete equa[i++];
	}

	delete[] equa;
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
	if (sN == nullptr)
	{
		return nullptr;
	}

	bool* newSN = new bool[STICKS_IN_A_NUM];

	for (int i = 0; i < STICKS_IN_A_NUM; i++)
	{
		newSN[i] = sN[i];
	}

	return newSN;
}

bool equal(const bool* r1, const bool* r2)
{
	if (r1 == nullptr 
		|| r2 == nullptr)
	{
		return false;
	}

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
	if (nR == nullptr)
	{
		return false;
	}

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
	if (sN == nullptr)
	{
		return nullptr;
	}

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
	if (sN == nullptr)
	{
		return nullptr;
	}

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
	if (sN == nullptr)
	{
		return nullptr;
	}

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
	if (sN == nullptr)
	{
		return -1;
	}

	for (int i = 0; i < 10; i++)
	{
		if (equal(STICK_REPRESENTATIONS[i], sN))
		{
			return i;
		}
	}

	return -1;
}

char* toStr(const int n1, const int n2, const int result, const char operation)
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

void orderEquation(const int i, const int j, int& n1, int& n2, int& result, const int aI, const int rI, bool** addStickComb, bool ** removeStickComb, bool** equation)
{
	if (addStickComb == nullptr 
		|| removeStickComb == nullptr
		|| equation == nullptr)
	{
		return;
	}

	if (i == N1_INDX)
	{
		n1 = getStickAsNum(removeStickComb[rI]);
		if (j != RES_INDX)
		{
			n2 = getStickAsNum(addStickComb[aI]);
			result = getStickAsNum(equation[RES_INDX]);
		}
		else
		{
			n2 = getStickAsNum(equation[N2_INDX]);
			result = getStickAsNum(addStickComb[aI]);
		}
	}
	else if (i == N2_INDX)
	{
		n2 = getStickAsNum(removeStickComb[rI]);
		if (j != RES_INDX)
		{
			n1 = getStickAsNum(addStickComb[aI]);
			result = getStickAsNum(equation[RES_INDX]);
		}
		else
		{
			n1 = getStickAsNum(equation[N1_INDX]);
			result = getStickAsNum(addStickComb[aI]);
		}
	}
	else if (i == RES_INDX)
	{
		result = getStickAsNum(removeStickComb[rI]);
		if (j == N2_INDX)
		{
			n1 = getStickAsNum(addStickComb[aI]);
			n2 = getStickAsNum(equation[N2_INDX]);
		}
		else
		{
			n2 = getStickAsNum(addStickComb[aI]);
			n1 = getStickAsNum(equation[N1_INDX]);
		}
	}
}

void orderEquation(const int i, int& n1, int& n2, int& result, const int aI, bool** comb, bool** equation)
{
	if (comb == nullptr
		|| equation == nullptr)
	{
		return;
	}

	if (i == N1_INDX)
	{
		n1 = getStickAsNum(comb[aI]);
		n2 = getStickAsNum(equation[N2_INDX]);
		result = getStickAsNum(equation[RES_INDX]);
	}
	else if (i == N2_INDX)
	{
		n1 = getStickAsNum(equation[N1_INDX]);
		n2 = getStickAsNum(comb[aI]);
		result = getStickAsNum(equation[RES_INDX]);
	}
	else if (i == RES_INDX)
	{
		n1 = getStickAsNum(equation[N1_INDX]);
		n2 = getStickAsNum(equation[N2_INDX]);
		result = getStickAsNum(comb[aI]);
	}
}

void checkStickSwitchCase(bool** equation, const char operation, char ** fixedEquations, int &index)
{
	if (fixedEquations == nullptr
		|| equation == nullptr)
	{
		return;
	}

	for (int i = 0; i < EQUATION_SIZE; i++)
	{
		bool** removeStickComb = getRemoveStickCombinations(equation[i]);
		for (int j = 0; j < EQUATION_SIZE; j++)
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
					
					orderEquation(i, j, n1,n2, result, aI, rI, addStickComb, removeStickComb, equation);

					if (operation == '+' && n1 + n2 == result)
					{
						fixedEquations[index++] = toStr(n1, n2, result, operation);
					}
					else if (operation == '-' && n1 - n2 == result)
					{
						fixedEquations[index++] = toStr(n1, n2, result, operation);
					}

					aI++;
				}
				rI++;
			}

			deleteComb(addStickComb);
		}
		deleteComb(removeStickComb);
	}

	return;
}

void checkSignSwitchCase(bool** equation, const char operation ,char** fixedEquations, int& index)
{
	if (fixedEquations == nullptr
		|| equation == nullptr)
	{
		return;
	}

	if (operation == '+')
	{
		for (int i = 0; i < EQUATION_SIZE; i++)
		{
			bool** addStickComb = getAddStickCombinations(equation[i]);
			int aI = 0;
			while (addStickComb[aI] != EMPTY_NUM)
			{
				int n1;
				int n2;
				int result;

				orderEquation(i, n1,n2,result, aI, addStickComb, equation);

				if (n1 - n2 == result)
				{
					fixedEquations[index++] = toStr(n1, n2, result, '-');
				}

				aI++;
			}

			deleteComb(addStickComb);
		}
	}

	if (operation == '-')
	{
		for (int i = 0; i < EQUATION_SIZE; i++)
		{
			bool** removeStickComb = getRemoveStickCombinations(equation[i]);
			int aI = 0;
			while (removeStickComb[aI] != EMPTY_NUM)
			{
				int n1;
				int n2;
				int result;

				orderEquation(i, n1, n2, result, aI, removeStickComb, equation);

				if (n1 + n2 == result)
				{
					fixedEquations[index++] = toStr(n1, n2, result, '+');
				}

				aI++;
			}

			deleteComb(removeStickComb);
		}
	}
	

	return;
}

void checkInNumberSwitchCase(bool** equation, const char operation, char** fixedEquations, int& index)
{
	if (fixedEquations == nullptr
		|| equation == nullptr)
	{
		return; 
	}

	for (int i = 0; i < EQUATION_SIZE; i++)
	{
		bool** moveStickComb = getMoveStickCombinations(equation[i]);
		int aI = 0;
		while (moveStickComb[aI] != EMPTY_NUM)
		{
			int n1;
			int n2;
			int result;

			orderEquation(i, n1, n2, result, aI, moveStickComb, equation);

			if (operation == '+' && n1 + n2 == result)
			{
				fixedEquations[index++] = toStr(n1, n2, result, operation);
			}
			else if (operation == '-' && n1 - n2 == result)
			{
				fixedEquations[index++] = toStr(n1, n2, result, operation);
			}

			aI++;
		}

		deleteComb(moveStickComb);
	}

	return;
}

char** fixEquation(char* str)
{
	if (str == nullptr || strlen(str) != 5)
	{
		return nullptr;
	}

	int n1 = str[0] - '0';
	char operation = str[1];
	char n2 = str[2] - '0';
	char result = str[4] - '0';

	bool* sN1 = STICK_REPRESENTATIONS[n1];
	bool* sN2 = STICK_REPRESENTATIONS[n2];
	bool* sR = STICK_REPRESENTATIONS[result];

	bool** equation = new bool* [EQUATION_SIZE];
	equation[N1_INDX] = sN1;
	equation[N2_INDX] = sN2;
	equation[RES_INDX] = sR;

	char** fixedEquations = new char* [100];
	int index = 0;

	checkStickSwitchCase(equation, operation, fixedEquations, index);
	checkInNumberSwitchCase(equation, operation, fixedEquations, index);
	checkSignSwitchCase(equation, operation, fixedEquations, index);

	char * end = new char[1];
	end[0] = '\0';
	fixedEquations[index] = end;

	delete[] equation;

	return fixedEquations;
}

int main()
{
	char str[6];

	std::cin >> str;

	char** fixedEquations = fixEquation(str);
	if (fixedEquations == nullptr)
	{
		std::cout << "-1";
		return 1;
	}
	if (fixedEquations[0][0] == '\0')
	{
		std::cout << "No";
	}
	else
	{
		int i = 0;
		while (fixedEquations[i][0] != '\0')
		{
			std::cout << fixedEquations[i++] << '\n';
		}
	}

	deleteEquations(fixedEquations);

	return 0;
}

