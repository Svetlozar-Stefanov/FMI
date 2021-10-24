#include <iostream>

using namespace std;

void checkOneToNine(int a) {
	switch (a)
	{
	case 1: cout << "one";
		break;
	case 2: cout << "two";
		break;
	case 3: cout << "three";
		break;
	case 4: cout << "four";
		break;
	case 5: cout << "five";
		break;
	case 6: cout << "six";
		break;
	case 7: cout << "seven";
		break;
	case 8: cout << "eight";
		break;
	case 9: cout << "nine";
		break;
	}
}

int main()
{
	int a;

	cin >> a;



	if (a >= 0 && a <= 100)
	{
		if (a < 20)
		{
			switch (a)
			{
			case 0: cout << "zero";
				break;
			case 10: cout << "ten";
				break;
			case 11: cout << "eleven";
				break;
			case 12: cout << "twelve";
				break;
			case 13: cout << "thirteen";
				break;
			case 14: cout << "fourteen";
				break;
			case 15: cout << "fifteen";
				break;
			case 16: cout << "sixteen";
				break;
			case 17: cout << "seventeen";
				break;
			case 18: cout << "eighteen";
				break;
			case 19: cout << "nineteen";
				break;
			}
			checkOneToNine(a);
		}
		if (a >= 20 && a < 30)
		{
			cout << "twenty-";
			checkOneToNine(a % 10);
		}
		if (a >= 30 && a < 40)
		{
			cout << "thirty-";
			checkOneToNine(a % 10);
		}
		if (a >= 40 && a < 50)
		{
			cout << "fourty-";
			checkOneToNine(a % 10);
		}
		if (a >= 50 && a < 60)
		{
			cout << "fifty-";
			checkOneToNine(a % 10);
		}
		if (a >= 60 && a < 70)
		{
			cout << "sixty-";
			checkOneToNine(a % 10);
		}
		if (a >= 70 && a < 80)
		{
			cout << "seventy-";
			checkOneToNine(a % 10);
		}
		if (a >= 80 && a < 90)
		{
			cout << "eighty-";
			checkOneToNine(a % 10);
		}
		if (a >= 90 && a < 100)
		{
			cout << "ninety-";
			checkOneToNine(a % 10);
		}
		if (a == 100)
		{
			cout << "one-hundred";
		}
	}
}
