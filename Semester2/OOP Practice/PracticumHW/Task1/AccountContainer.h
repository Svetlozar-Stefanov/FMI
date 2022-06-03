#pragma once
#include "Account.h"

class AccountContainer
{
public:
	AccountContainer();
	AccountContainer(const AccountContainer& other);
	AccountContainer& operator=(const AccountContainer& other);
	~AccountContainer();

	int length() const;
	void Add(const Account& acc);
	bool Delete(const int i);

	bool Withdraw(const myString& IBAN, const double amount);
	bool Deposit(const myString& IBAN, const double amount);
	bool Transfer(const myString& fromIBAN, const myString& toIBAN, const double amount);

	const Account& operator[](const int i) const;

private:
	Account** items;
	int index, size;

	void free();
	void copy(const AccountContainer& other);
	void resize();
};

