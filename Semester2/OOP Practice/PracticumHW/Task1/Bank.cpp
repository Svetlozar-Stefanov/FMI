#include "Bank.h"

void Bank::Display() const
{
	std::cout << "Name: " << name << " Address: " << address
		<< " Customers: " << customers.length() << "Accounts: " << accounts.length() << '\n';
}

Bank::Bank(const myString& name, const myString& address)
{
	this->name = name;
	this->address = address;
}

Bank::~Bank()
{
}

bool Bank::AddCustomer(const Customer& newCustomer)
{
	for (int i = 0; i < customers.length(); i++)
	{
		if (customers[i].GetID() == newCustomer.GetID())
		{
			return false;
		}
	}

	customers.Add(newCustomer);

	myString logInfo("Added customer ");
	logInfo += newCustomer.GetName();
	logInfo += " ";
	logInfo += (int)newCustomer.GetID();
	logInfo += "\n";

	log.Add(logInfo);

	return true;
}

bool Bank::DeleteCustomer(const unsigned userID)
{
	for (int i = 0; i < customers.length(); i++)
	{
		if (customers[i].GetID() == userID)
		{
			for (int i = 0; i < accounts.length(); i++)
			{
				if (accounts[i].isOwnedBy(userID))
				{
					DeleteAccount(accounts[i].GetIBAN());
					if (i > 0)
					{
						i--;
					}
				}
			}

			myString logInfo("Deleted customer ");
			logInfo += customers[i].GetName();
			logInfo += " ";
			logInfo += (int)customers[i].GetID();
			logInfo += "\n";

			log.Add(logInfo);

			customers.Delete(i);

			return true;
		}
	}

	return false;
}

bool Bank::AddAccount(const Account& newAccount)
{
	bool hasOwner = false;
	for (int i = 0; i < customers.length(); i++)
	{
		if (newAccount.isOwnedBy(customers[i].GetID()))
		{
			hasOwner = true;
			break;
		}
	}

	if (hasOwner)
	{
		accounts.Add(newAccount);
	}
	else
	{
		return false;
	}

	myString logInfo("Opened account ");
	logInfo += newAccount.GetName();
	logInfo += " ";
	logInfo += newAccount.GetIBAN();
	logInfo += " ";
	logInfo += newAccount.GetDate();
	logInfo += "\n";

	log.Add(logInfo);

	return hasOwner;
}

bool Bank::DeleteAccount(const myString& IBAN)
{
	for (int i = 0; i < accounts.length(); i++)
	{
		if (accounts[i].GetIBAN() == IBAN)
		{
			myString logInfo("Deleted account ");
			logInfo += accounts[i].GetName();
			logInfo += " ";
			logInfo += accounts[i].GetIBAN();
			logInfo += "\n";

			log.Add(logInfo);

			accounts.Delete(i);

			return true;
		}
	}

	return false;
}

int Bank::GetCustomersCount() const
{
	return customers.length();
}

int Bank::GetAccountsCount() const
{
	return accounts.length();
}

const myVector<myString>& Bank::GetLog() const
{
	return log;
}

void Bank::ListCustomers() const
{
	for (int i = 0; i < customers.length(); i++)
	{
		if (customers[i].GetID() != -1)
		{
			customers[i].print();
		}
	}
}

void Bank::ListAccounts() const
{
	for (int i = 0; i < accounts.length(); i++)
	{
		accounts[i].Display();
	}
}

void Bank::ListAccounts(const unsigned userID) const
{
	for (int i = 0; i < accounts.length(); i++)
	{
		if (accounts[i].isOwnedBy(userID))
		{
			accounts[i].Display();
		}
	}
}

bool Bank::ExportLog(const char* filePath) const
{
	std::ofstream file(filePath);

	for (int i = 0; i < log.length(); i++)
	{
		file << log[i];
	}

	file.close();

	return true;
}

bool Bank::Withdraw(const myString& IBAN, const double amount)
{	
	if (accounts.Withdraw(IBAN, amount))
	{
		myString logInfo("Withdrawn ");
		logInfo += (float)amount;
		logInfo += " from ";
		logInfo += IBAN;
		logInfo += "\n";

		log.Add(logInfo);

		return true;
	}
	return false;
}

bool Bank::Deposit(const myString& IBAN, const double amount)
{
	if (accounts.Deposit(IBAN, amount))
	{
		myString logInfo("Deposited ");
		logInfo += (float)amount;
		logInfo += " to ";
		logInfo += IBAN;
		logInfo += "\n";

		log.Add(logInfo);

		return true;
	} 
	return false;
}

bool Bank::Transfer(const myString& fromIBAN, const myString& toIBAN, const double amount)
{
	if (accounts.Transfer(fromIBAN, toIBAN, amount))
	{
		myString logInfo("Transfered ");
		logInfo += (float)amount;
		logInfo += " from ";
		logInfo += fromIBAN;
		logInfo += " to ";
		logInfo += toIBAN;
		logInfo += "\n";

		log.Add(logInfo);

		return true;
	} 
}
