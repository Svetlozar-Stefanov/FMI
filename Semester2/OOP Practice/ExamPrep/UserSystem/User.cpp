#include "User.h"

User::User(const char* name, const char* pass) 
	: IUser(name, pass)
{
	type = Type::FREE;
}

double User::getDailyProfit() const
{
	return dailyProfit;
}

void User::setDailyProfit(const double profit)
{
	dailyProfit = profit;
}

double User::getMonthlyProfit() const
{
	return dailyProfit * 30.5f;
}

IUser* User::clone() const
{
	return new User(*this);
}
