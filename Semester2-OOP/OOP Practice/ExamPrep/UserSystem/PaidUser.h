#pragma once
#include "IUser.h"
enum class Subscrption
{
    Normal,
    Gold,
    Platinum,
    UNKNOWN
};

class PaidUser :
    public IUser
{
public:
    PaidUser(Subscrption subs, double monthlyFee, const char* name, const char* pass);
    double getFee() const;
    void setFee(const double fee);

    Subscrption getSubscription() const;
    void setSubscription(Subscrption subs);

    double getMonthlyProfit() const;
    IUser* clone() const;
private:
    double monthlyFee;
    Subscrption subscription;
};

