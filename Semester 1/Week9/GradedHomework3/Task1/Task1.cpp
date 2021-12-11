#include <iostream>

using namespace std;

unsigned strlen(const char ch[]) 
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
	if (strlen(word1) != strlen(word2))
	{
		return true;
	}

	return false;
}

bool changedLetter(const char word1[], const char word2[])
{
	bool changed = false;

	for (int i = 0; i < strlen(word1); i++)
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
		if (!(changedLetterCount(sequence[i], sequence[i + 1]) || changedLetter(sequence[i], sequence[i + 1])))
		{
			correct = false;
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

	cout << isCorrect(sequence, N);
}