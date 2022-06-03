#pragma once
#include "Account.h"
class SavingsAccount :
    public Account
{
public:
    SavingsAccount(const myString& name, const myString& password, const myString& IBAN, 
        const unsigned id, const double rate);

    bool Withdraw(const double sum) override;

    double GetInterestRate() const;
    void Display() const override;

    Account* clone() const override;
private:
    double interestRate;
};

