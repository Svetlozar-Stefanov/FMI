#include <iostream>

using namespace std;

int main()
{
	int input;

	cin >> input;
	
	if (input >= 100)
	{
		int firstDigit;
		int secondDigit;
		int lastDigit;

		if (input >= 1000)
		{
			firstDigit = 9;
			secondDigit = 9;
			lastDigit = 9;
		}
		else
		{
			firstDigit = (input - input % 100) / 100;
			secondDigit = (input % 100 - input % 10) / 10;
			lastDigit = input % 10;
		}
		

		

		for (int fd = firstDigit; fd >= 1; fd--)
		{
			for (int sd = secondDigit; sd >= 0; sd--)
			{
				for (int ld = lastDigit - 1; ld >= 0; ld--)
				{
					if (fd != sd && fd != ld && sd != ld)
					{
						cout << fd << " " << sd << " " << ld << endl;
					}
				}
			}
		}
	}
}
