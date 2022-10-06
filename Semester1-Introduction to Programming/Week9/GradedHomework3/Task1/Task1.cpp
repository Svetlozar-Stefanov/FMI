/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int absolute(const int a) 
{
	return a < 0 ? -a : a;
}

unsigned strleng(const char ch[]) 
{
	unsigned counter = 0;

	int i = 0;
	while (ch[i] != '\0')
	{
		counter++;
		i++;
	}

	return counter;
}

bool changedLetterCount(const char word1[],const char word2[]) 
{
	if (absolute(strleng(word1) - strleng(word2)) == 1)
	{
		return true;
	}

	return false;
}

bool changedLetter(const char word1[], const char word2[])
{
	bool changed = false;

	for (int i = 0; i < strleng(word1); i++)
	{
		if (!changed && word1[i] != word2[i])
		{
			changed = true;
		}
		else if (changed && word1[i] != word2[i])
		{
			changed = false;
			break;
		}
	}

	return changed;
}

bool isCorrect(const char sequence[][20], const int sequenceSize) 
{
	bool correct = true;

	for (int i = 0; i < sequenceSize - 1; i++)
	{
		if (!(changedLetterCount(sequence[i], sequence[i + 1]) 
			|| changedLetter(sequence[i], sequence[i + 1])))
		{
			correct = false;
			break;
		}
	}

	return correct;
}

int main()
{
	int N;
	char sequence[50][20];

	if (!(cin>>N)
		|| N < 2 || N > 50)
	{
		cout << "-1";
		return 1;  
	}

	for (int i = 0; i < N; i++)
	{
		cin >> sequence[i];
	}

	if (isCorrect(sequence, N))
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
} 