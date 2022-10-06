#include "Account.h"

Account::Account(const myString& name, const myString& password, const myString& IBAN, const unsigned id)
{
	this->name = name;
	this->password = password;
	this->IBAN = IBAN;
	this->userID = id;

	amount = 0.0f;
	time_t t = 0;
	time(&t);

	creationDate = convTime(t);
}

const myString& Account::GetName() const
{
	return name;
}

const myString& Account::GetIBAN() const
{
	return IBAN;
}

bool Account::isOwnedBy(const unsigned userID) const
{
	return this->userID == userID;
}

double Account::GetBalance() const
{
	return amount;
}

const myString& Account::GetDate() const
{
	return creationDate;
}

bool Account::Deposit(const double sum)
{
	if (sum < 0.0f)
	{
		return false;
	}
	amount += sum;
	return true;
}

bool Account::Withdraw(const double sum)
{
	if (amount - sum >= 0.0f)
	{
		amount -= sum;
		return true;
	}
	return false;
}

bool Account::checkIfLeap(const int year) const
{
	if (year % 100 == 0 || year % 400 == 0)
	{
		return true;
	}
	if (year % 4 == 0 && year % 100 != 0)
	{
		return true;
	}

	return false;
}

myString Account::convTime(time_t t) const
{
	int minutes = t / 60;
	int hours = minutes / 60;
	int days = (hours / 24) + 1;

	int month = 1;
	int year = 1970;

	bool isLeap = checkIfLeap(year);

	while (true)
	{
		if (month == 2)
		{
			if (isLeap && days > 29)
			{
				days -= 29;
				month++;
			}
			else if (!isLeap && days > 28)
			{
				days -= 28;
				month++;
			}
			else break;
		}
		else if (month == 1 ||
			month == 3 ||
			month == 5 ||
			month == 7 ||
			month == 8 ||
			month == 10 ||
			month == 12)
		{
			if (days > 31)
			{
				days -= 31;
				if (month >= 12)
				{
					year++;
					isLeap = checkIfLeap(year);
					month = 0;
				}
				month++;
			}
			else
			{
				break;
			}
		}
		else
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
	}

	myString out;
	out += days;
	out += "/";
	out += month;
	out += "/";
	out += year;

	return out;
}
