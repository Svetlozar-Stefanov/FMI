#pragma once
#include "Account.h"
class NormalAccount :
    public Account
{
public:
    NormalAccount(const myString& name, const myString& password, const myString& IBAN, const unsigned id);
    void Display() const override;
    Account* clone() const override;
};

