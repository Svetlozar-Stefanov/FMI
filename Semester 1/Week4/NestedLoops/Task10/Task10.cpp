#include <iostream>

using namespace std;

int main()
{
	const int hoursIndex = 1;
	const int minutesIndex = 2;
	const int secondsIndex = 5;


	char clockOne[7];
	char clockTwo[7];

	int movieLength[3];

	cin >> clockOne;
	cin >> clockTwo;
	for (int i = 0; i < 3; i++)
	{
		cin >> movieLength[i];
	}


	for (int h = 0; h <= 1; h++)
	{
		if (h == 1 && clockOne[hoursIndex] - '0' >0)
		{
			break;
		}
		for (int m = 0; m <= 9; m++)
		{
			for (int s = 0; s <= 5; s++)
			{
				int seconds = s * 10 + clockOne[secondsIndex] - '0';
				int minutes = (clockOne[minutesIndex] - '0') * 10 + m;
				int hour = h * 10 + clockOne[hoursIndex] - '0';

				int newSeconds = (seconds + movieLength[2]) - (((seconds + movieLength[2]) / 60) * 60);
				int newMinutes = (minutes + movieLength[1] + (seconds + movieLength[2]) / 60) 
					- (((minutes + movieLength[1] + (seconds + movieLength[2]) / 60) / 60) * 60);
				int newHour = hour + movieLength[0] + ((minutes + movieLength[1] + (seconds + movieLength[2]) / 60) / 60);

				newHour = newHour - ((newHour / 12) * 12);

				if (newSeconds % 10 == clockTwo[secondsIndex] - '0'
					&& newMinutes / 10 == clockTwo[minutesIndex] - '0'
					&& newHour % 10 == clockTwo[hoursIndex] - '0')
				{
					cout << hour / 10 << hour % 10 << ":" << minutes / 10 << minutes % 10 << ":" << seconds / 10 << seconds % 10 << " ";

					cout << newHour / 10 << newHour % 10 << ":" << newMinutes / 10 << newMinutes % 10 << ":" << newSeconds / 10 << newSeconds % 10 << endl;
				}
			}
		}
	}
}
