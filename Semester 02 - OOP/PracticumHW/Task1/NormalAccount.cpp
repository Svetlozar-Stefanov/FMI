#include "NormalAccount.h"

NormalAccount::NormalAccount(const myString& name, const myString& password, const myString& IBAN, const unsigned id)
	:Account(name, password, IBAN, id)
{
	type = Type::NORMAL;
}

void NormalAccount::Display() const
{
	std::cout << "Type: Normal IBAN: " << IBAN << " UserID: " << userID << " Balance: " << amount << '\n';
}

Account* NormalAccount::clone() const
{
	return new NormalAccount(*this);
}
