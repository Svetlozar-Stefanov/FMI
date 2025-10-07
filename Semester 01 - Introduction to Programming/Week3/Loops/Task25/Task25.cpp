#include <iostream>

using namespace std;

int main()
{
	int input = 0;

	cin >> input;

	if (input > 9)
	{
		int digitCount = 0;
		int divider = 1;

		while (input / divider != 0)
		{
			digitCount++;
			divider *= 10;
		}

		const int numberOfDigits = digitCount;

		int* digits = new int[numberOfDigits];

		int digitMultiplication = 1;

		divider = pow(10, numberOfDigits);
		for (int i = 0; i < numberOfDigits; i++)
		{
			int currentDigit = ((input % divider) - (input % (divider / 10))) / (divider / 10);
			digitMultiplication *= currentDigit;

			digits[i] = currentDigit;

			divider /= 10;
		}

		int sumFirstAndLastDigit = digits[0] + digits[numberOfDigits - 1];

		int reversedFLNumber = digits[numberOfDigits - 1] * pow(10, numberOfDigits - 1);
		for (int i = 1; i < numberOfDigits - 1; i++)
		{
			reversedFLNumber += digits[i] * pow(10, numberOfDigits - i - 1);
		}
		reversedFLNumber += digits[0];

		int reversedNumber = 0;
		for (int i = 0; i < numberOfDigits; i++)
		{
			reversedNumber += digits[i] * pow(10, i);
		}

		bool isPalindrome = reversedNumber == input;

		cout << numberOfDigits << endl;
		cout << sumFirstAndLastDigit << endl;
		cout << reversedFLNumber << endl;
		cout << digitMultiplication << endl;
		cout << reversedNumber << endl;
		if (isPalindrome)
		{
			cout << "Is Palindrome\n";
		}
		else
		{
			cout << "Is Not a Palindrome\n";
		}

		for (int i = 0; i < numberOfDigits; i++)
		{
			int counter = 0;
			bool alradyCounted = false;
			for (int j = 0; j < numberOfDigits; j++)
			{
				if (digits[i] == digits[j])
				{
					counter++;
					if (j < i)
					{
						alradyCounted = true;
						break;
					}
				}
			}
			if (!alradyCounted)
			{
				cout << digits[i] << "-" << counter << endl;
			}
		}

	}
}
