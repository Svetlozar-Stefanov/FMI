#include <iostream>
#include "myString.h"
#include "Bank.h"
#include "NormalAccount.h"
#include "SavingsAccount.h"
#include "PrivilegeAccount.h"


int main()
{
	Bank bank = Bank("Dsk", "Sofia");

	char raw[1024];
	std::cout << ">";
	std::cin.getline(raw, 1024);
	myString input(raw);
	while (input != "quit")
	{
		if (input == "edit")
		{
			std::cout << ">>";
			std::cin.getline(raw, 1024);
			myString input(raw);
			if (input == "add user")
			{
				std::cout << "Name: ";
				std::cin.getline(raw, 1024);
				myString name(raw);

				std::cout << "Address: ";
				std::cin.getline(raw, 1024);
				myString address(raw);

				Customer newCustomer(bank.GetCustomersCount(), name, address);
				if (bank.AddCustomer(newCustomer))
				{
					std::cout << "Operation successful!\n";
				}
			}
			else if (input == "add account")
			{
				std::cout << "Type: ";
				std::cin.getline(raw, 1024);
				myString type(raw);

				std::cout << "Name: ";
				std::cin.getline(raw, 1024);
				myString name(raw);

				std::cout << "Password: ";
				std::cin.getline(raw, 1024);
				myString password(raw);

				std::cout << "IBAN: ";
				std::cin.getline(raw, 1024);
				myString IBAN(raw);

				std::cout << "User ID: ";
				std::cin.getline(raw, 1024);

				int id = stoi(raw);

				if (type == "normal")
				{
					NormalAccount newAccount(name, password, IBAN, id);
					if (bank.AddAccount(newAccount))
					{
						std::cout << "Operation successful!\n";
					}
				}
				else if (type == "savings")
				{
					std::cout << "Rate: ";
					std::cin.getline(raw, 1024);

					SavingsAccount newAccount(name, password, IBAN, id, stof(raw));
					if (bank.AddAccount(newAccount))
					{
						std::cout << "Operation successful!\n";
					}
				}
				else if (type == "privilege")
				{
					std::cout << "Overdraft: ";
					std::cin.getline(raw, 1024);

					PrivilegeAccount newAccount(name, password, IBAN, id, stof(raw));
					if (bank.AddAccount(newAccount))
					{
						std::cout << "Operation successful!\n";
					}
				}
			}
			else if (input == "delete user")
			{
				std::cout << "User ID: ";
				std::cin.getline(raw, 1024);

				int id = stoi(raw);

				if (bank.DeleteCustomer(id))
				{
					std::cout << "Operation successful!\n";
				}
			}
			else if (input == "delete account")
			{
				std::cout << "IBAN: ";
				std::cin.getline(raw, 1024);
				myString IBAN(raw);

				if (bank.DeleteAccount(IBAN))
				{
					std::cout << "Operation successful!\n";
				}
			}
		}
		else if (input == "list")
		{
			std::cout << ">>";
			std::cin.getline(raw, 1024);
			myString input(raw);
			if (input == "all customers")
			{
				bank.ListCustomers();
			}
			else if (input == "all accounts")
			{
				bank.ListAccounts();
			}
			else if (input == "account")
			{
				std::cout << "User ID: ";
				std::cin >> raw;

				int id = stoi(raw);

				bank.ListAccounts(id);
			}
			else if (input == "log")
			{
				for (int i = 0; i < bank.GetLog().length(); i++)
				{
					std::cout << bank.GetLog()[i];
				}
			}
			else if (input == "export log")
			{
				std::cout << "path: ";
				std::cin.getline(raw, 1024);
				
				if (bank.ExportLog(raw))
				{
					std::cout << "Operation successful!\n";
				}
			}
		}
		else if (input == "action")
		{
			std::cout << ">>";
			std::cin.getline(raw, 1024);
			myString input(raw);
			if (input == "withdraw")
			{
				std::cout << "IBAN: ";
				std::cin.getline(raw, 1024);
				myString IBAN(raw);

				std::cout << "Amount: ";
				std::cin.getline(raw, 1024);

				if (bank.Withdraw(IBAN, stof(raw)))
				{
					std::cout << "Operation successful!\n";
				}
			}
			else if (input == "deposit")
			{
				std::cout << "IBAN: ";
				std::cin.getline(raw, 1024);
				myString IBAN(raw);

				std::cout << "Amount: ";
				std::cin.getline(raw, 1024);

				if (bank.Deposit(IBAN, stof(raw)))
				{
					std::cout << "Operation successful!\n";
				}
			}
			else if (input == "transfer")
			{
				std::cout << "from IBAN: ";
				std::cin.getline(raw, 1024);
				myString fromIBAN(raw);

				std::cout << "to IBAN: ";
				std::cin.getline(raw, 1024);
				myString toIBAN(raw);

				std::cout << "Amount: ";
				std::cin.getline(raw, 1024);

				if (bank.Transfer(fromIBAN, toIBAN, stof(raw))) 
				{
					std::cout << "Operation successful!\n";
				}
			}
		}
		else if (input == "display")
		{
			bank.Display();
		}

		std::cout << ">";
		std::cin.getline(raw, 1024);
		input = raw;
	}
}