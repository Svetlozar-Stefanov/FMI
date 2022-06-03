#pragma once
#include <fstream>
#include "myString.h"
#include "myVector.h"
#include "Customer.h"
#include "AccountContainer.h"

class Bank
{
public:
	Bank(const myString& name, const myString& address);
	~Bank();

	bool AddCustomer(const Customer& newCustomer);
	bool DeleteCustomer(const unsigned userID);
	bool AddAccount(const Account& newAccount);
	bool DeleteAccount(const myString& IBAN);

	int GetCustomersCount() const;
	int GetAccountsCount() const;

	const myVector<myString>& GetLog() const;

	void ListCustomers() const;
	void ListAccounts() const;
	void ListAccounts(const unsigned userID) const;
	bool ExportLog(const char* filePath) const;

	bool Withdraw(const myString& IBAN, const double amount);
	bool Deposit(const myString& IBAN, const double amount);
	bool Transfer(const myString& fromIBAN, const myString& toIBAN, const double amount);
	void Display() const;


private:
	myString name;
	myString address;
	myVector<Customer> customers;
	AccountContainer accounts;
	myVector<myString> log;
};

