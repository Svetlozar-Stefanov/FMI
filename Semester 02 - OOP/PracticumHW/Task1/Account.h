#pragma once
#include <iostream>
#include <ctime>
#include "myString.h"

class Account
{
public:
	Account(const myString& name, const myString& password, const myString& IBAN, const unsigned id);

	const myString& GetName() const;
	const myString& GetIBAN() const;
	bool isOwnedBy(const unsigned userID) const;
	double GetBalance() const;
	const myString& GetDate() const;

	virtual bool Deposit(const double sum);
	virtual bool Withdraw(const double sum);
	virtual void Display() const = 0;

	virtual Account* clone() const = 0;

protected:
	enum Type
	{
		NORMAL,
		SAVINGS,
		PRIVILAGE,
		OTHER
	} type;

	myString name;
	myString password;
	myString IBAN;
	unsigned userID;

	double amount;
	myString creationDate;

private:
	bool checkIfLeap(const int year) const;
	myString convTime(time_t t) const;
};

