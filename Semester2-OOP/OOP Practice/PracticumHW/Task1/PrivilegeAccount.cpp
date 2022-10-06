#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(const myString& name, const myString& password, const myString& IBAN,
    const unsigned id, const double overdraft)
    : Account(name, password, IBAN, id)
{
    type = Type::PRIVILAGE;
    this->overdraft = overdraft;
}

bool PrivilegeAccount::Withdraw(const double sum)
{
    if (amount + overdraft - sum < 0.0f)
    {
        return false;
    }

    amount -= sum;
    return true;
}

double PrivilegeAccount::GetOverdraft() const
{
    return overdraft;
}

void PrivilegeAccount::Display() const
{
    std::cout << "Type: Privilaged IBAN: " << IBAN << " UserID: " << userID << " Balance: " << amount << '\n';
}

Account* PrivilegeAccount::clone() const
{
    return new PrivilegeAccount(*this);
}
