#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(const myString& name, const myString& password, const myString& IBAN,
    const unsigned id, const double rate)
    : Account(name, password, IBAN, id)
{
    type = Type::SAVINGS;
    interestRate = rate;
}

bool SavingsAccount::Withdraw(const double sum)
{
    return false;
}

double SavingsAccount::GetInterestRate() const
{
    return interestRate;
}

void SavingsAccount::Display() const
{
    std::cout << "Type: Savings IBAN: " << IBAN << " UserID: " << userID << " Balance: " << amount << '\n';
}

Account* SavingsAccount::clone() const
{
    return new SavingsAccount(*this);
}
