/**
*
* Solution to homework assignment 3
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

using namespace std;

const char BOT_A = 35;
const char CAP_A = 55;

const char BOT_B = 64;
const char CAP_B = 96;

int inputValidation(int& a, int& b, int& maxPass)
{
	if (!(cin >> a)
		|| a < 1 || a > 1000)
	{
		return 1;
	}

	if (!(cin >> b)
		|| b < 1 || b > 1000)
	{
		return 1;
	}

	if (!(cin >> maxPass)
		|| maxPass < 1 || maxPass > 1000000)
	{
		return 1;
	}

	return 0;
}

void generatePasswords(const int botA, const int capA,
	const int botB, const int capB
	, const int a, const int b, const int maxPass)
{
	int passGenerated = 0;
	char A = botA;
	char B = botB;

	for (int x = 1; x <= a; x++)
	{
		for (int y = 1; y <= b; y++)
		{
			if (passGenerated >= maxPass)
			{
				return;
			}

			cout << A << B << x << y << B << A << '|';
			passGenerated++;

			if (A >= capA)
			{
				A = botA;
			}
			else
			{
				A++;
			}

			if (B >= capB)
			{
				B = botB;
			}
			else
			{
				B++;
			}
		}
	}
}

int main()
{
	int a;
	int b;

	int maxPass;

	if (inputValidation(a, b, maxPass) != 0)
	{
		cout << "-1";
		return 1;
	}

	generatePasswords(BOT_A, CAP_A,
		BOT_B, CAP_B,
		a, b, maxPass);
}
