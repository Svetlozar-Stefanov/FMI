/**
*
* Solution to homework assignment 1
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

int main()
{
	const int fbFine = 150;
	const int igFine = 100;
	const int rtFine = 50;

	double inputN;
	double inputSalary;

	if (!(cin >> inputN)
		|| !(1 <= inputN && inputN <= 10)
		|| inputN - (int)inputN != 0)
	{
		cout << "-1";
		return 1;
	}
	unsigned int n = inputN;

	if (!(cin >> inputSalary)
		|| !(700 <= inputSalary && inputSalary <= 1500))
	{
		cout << "-1";
		return 1;
	}
	double salary = inputSalary;


	char tab;
	for (int i = 0; i < n; i++)
	{
		cin >> tab;
		if (tab == 'F')
		{
			salary -= fbFine;
		}
		else if (tab == 'I')
		{
			salary -= igFine;
		}
		else if (tab == 'R')
		{
			salary -= rtFine;
		}
		else if (tab != 'd')
		{
			cout << "-1\n";
		}

		if (salary <= 0)
		{
			cout << "You have lost your salary.";
			return 0;
		}
	}
		
	cout << salary;
	return 0;
}