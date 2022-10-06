#include <iostream>

using namespace std;

int main()
{
	int day;
	int month;
	int year;

	cin >> day;
	cin >> month;
	cin >> year;
	

	if (month < 8)
	{
		if (month % 2 == 1 && day == 31)
		{
			day = 1;
			month++;
		}
		else if (month != 2 && month % 2 == 0 && day == 30)
		{
			day = 1;
			month++;
		}
		else if (month == 2)
		{
			if ((year % 4 == 0 && year % 100 != 0) 
				|| year % 400 == 0)
			{
				if (day == 29)
				{
					day = 1;
					month++;
				}
			}
			else if(day == 28)
			{
				day = 1;
				month++;
			}
			
		}
		else
		{
			day++;
		}
	}
	else if (month >= 8)
	{
		if (month != 12 && month % 2 == 0 && day == 31)
		{
			day = 1;
			month++;
		}
		else if (month == 12)
		{
				day = 1;
				month = 1;
				year++;
		}
		else if(month % 2 == 1 && day == 30)
		{
			day = 1;
			month++;
		}
		else
		{
			day++;
		}
		
	}
	

	cout << day << " " << month << " " << year;
}