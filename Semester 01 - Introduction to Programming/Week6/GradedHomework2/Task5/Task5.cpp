/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Svetlozar Stefanov
* @idnumber 4MI0600030
* @task 5
* @compiler VC
*
*/

#include <iostream>
#include <vector>

using namespace std;

const unsigned SEC_IN_MIN = 60;
const unsigned MIN_IN_HOUR = 60;
const unsigned SEC_IN_HOUR = 3600;
const unsigned HOURS_IN_DAY = 24; 
const unsigned MONTHS_IN_YEAR = 12;

const unsigned START_DAY = 1;
const unsigned START_MONTH = 1;
const unsigned START_YEAR = 1970;

const vector<unsigned> MONTHS_31_DAYS = { 1, 3, 5, 7, 8, 10, 12 };
const vector<unsigned> MONTHS_30_DAYS = {4, 6, 9, 11};

bool contains(const vector<unsigned> setOFMonths, const unsigned int month)
{
	bool contains = false;
	int size = setOFMonths.size();

	for (int i = 0; i < size; i++)
	{
		if (month == setOFMonths[i])
		{
			contains = true;
			break;
		}
	}

	return contains;
}

bool isLeap(const unsigned int year) 
{
	bool leap = false;
	
	if ((year % 4 == 0 && year % 400 != 0)
		|| year % 400 == 0)
	{
		leap = true;
	}

	return leap;
}

void fprint(const unsigned int n) 
{
	if (n >= 10)
	{
		cout << n;
	}
	else
	{
		cout << '0' << n;
	}
}

void printTime(const unsigned int day, 
	const unsigned int month, 
	const unsigned int year, 
	const unsigned int hour, 
	const unsigned int minute, 
	const unsigned int seconds)
{
	fprint(day);
	cout << '.';
	fprint(month);
	cout << '.';
	cout << year;
	cout << ' ';
	fprint(hour);
	cout << ':';
	fprint(minute);
	cout << ':';
	fprint(seconds);
}

int main()
{
    int input;

	if (!(cin>>input) || input < 0)
	{
		cout << "-1";
		return 1;
	}

	unsigned int seconds = input % SEC_IN_MIN;
	unsigned int minutes = (input / SEC_IN_MIN) % MIN_IN_HOUR;
	unsigned int hours = (input / SEC_IN_HOUR) % HOURS_IN_DAY;

	unsigned int days = START_DAY + (input / SEC_IN_HOUR) / HOURS_IN_DAY;
	unsigned int month = START_MONTH;
	unsigned int year = START_YEAR;

	while (true)
	{
		if (month > MONTHS_IN_YEAR)
		{
			month = 1;
			year++;
		}

		if (contains(MONTHS_31_DAYS, month))
		{
			if (days > 31)
			{
				days -= 31;
				month++;
			}
			else
			{
				break;
			}
		}
		else if(contains(MONTHS_30_DAYS, month))
		{
			if (days > 30)
			{
				days -= 30;
				month++;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (isLeap(year))
			{
				if (days > 29)
				{
					days -= 29;
					month++;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (days > 28)
				{
					days -= 28;
					month++;
				}
				else
				{
					break;
				}
			}
		}
	}

	printTime(days, month, year, hours, minutes, seconds);
}
