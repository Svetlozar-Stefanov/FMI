#include "PaidUser.h"

PaidUser::PaidUser(Subscrption subs, double monthlyFee, const char* name, const char* pass)
    : IUser(name, pass)
{
    type = Type::PAID;
    subscription = subs;
    this->monthlyFee = monthlyFee;
}

double PaidUser::getFee() const
{
    return monthlyFee;
}

void PaidUser::setFee(const double fee)
{
    monthlyFee = fee;
}

Subscrption PaidUser::getSubscription() const
{
    return subscription;
}

void PaidUser::setSubscription(Subscrption subs)
{
    subscription = subs;
}

double PaidUser::getMonthlyProfit() const
{
    return monthlyFee;
}

IUser* PaidUser::clone() const
{
    return new PaidUser(*this);
}
