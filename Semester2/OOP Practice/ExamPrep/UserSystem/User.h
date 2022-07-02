#pragma once
#include "IUser.h"
class User :
    public IUser
{
public:
    User(const char* name, const char* pass);
    double getDailyProfit() const;
    void setDailyProfit(const double profit);

    double getMonthlyProfit() const;
    IUser* clone() const;
private:
    double dailyProfit;
};

