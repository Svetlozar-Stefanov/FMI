#include <iostream>
using namespace std;

string signs;
long long chCount[62] = { 0 };

int getNumber(char a) {
	int num = 0;
	if (a >= '0' && a <= '9')
	{
		num = a - 47;
	}
	else if (a >= 'A' && a <= 'Z')
	{
		num = a - 28;
	}
	else if (a >= 'a' && a <= 'z')
	{
		num = a - 86;
	}

	return num;
}

char getChar(int a) {
	char num = 0;
	if (a >= 1 && a <= 10)
	{
		num = a + 47;
	}
	else if (a >= 37 && a <= 62)
	{
		num = a + 28;
	}
	else if (a >= 11 && a <= 36)
	{
		num = a + 86;
	}

	return (char)num;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;
	cin >> signs;

	for (int i = 0; i < N; i++)
	{
		chCount[getNumber(signs[i]) - 1]++;
	}

	for (int i = 0; i < 62; i++)
	{
		char s = getChar(i + 1);
		for (int j = 0; j < chCount[i]; j++)
		{
			cout << s;
		}
	}
}