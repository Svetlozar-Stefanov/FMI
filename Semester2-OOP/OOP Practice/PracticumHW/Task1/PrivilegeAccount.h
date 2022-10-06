#pragma once
#include "Account.h"

class PrivilegeAccount
	: public Account
{
public:
	PrivilegeAccount(const myString& name, const myString& password, const myString& IBAN,
		const unsigned id, const double overdraft);

	bool Withdraw(const double sum) override;

	double GetOverdraft() const;
	void Display() const override;

	Account* clone() const override;
private:
	double overdraft;
};

