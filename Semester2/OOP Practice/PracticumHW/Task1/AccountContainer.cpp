#include "AccountContainer.h"


AccountContainer::AccountContainer()
{
	index = 0;
	size = 5;
	items = new Account * [size];
}

AccountContainer::AccountContainer(const AccountContainer& other)
{
	copy(other);
}

AccountContainer& AccountContainer::operator=(const AccountContainer& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

AccountContainer::~AccountContainer()
{
	free();
}

int AccountContainer::length() const
{
	return index;
}

void AccountContainer::Add(const Account& el)
{
	if (index >= size)
	{
		resize();
	}

	items[index++] = el.clone();
}

bool AccountContainer::Delete(const int i)
{
	if (i >= index)
	{
		return false;
	}

	delete items[i];
	items[i] = items[--index];
	items[index] = nullptr;

	return true;
}

bool AccountContainer::Withdraw(const myString& IBAN, const double amount)
{
	for (int i = 0; i < index; i++)
	{
		if (items[i]->GetIBAN() == IBAN)
		{
			return items[i]->Withdraw(amount);
		}
	}
	return false;
}

bool AccountContainer::Deposit(const myString& IBAN, const double amount)
{
	for (int i = 0; i < index; i++)
	{
		if (items[i]->GetIBAN() == IBAN)
		{
			return items[i]->Deposit(amount);
		}
	}
	return false;
}

bool AccountContainer::Transfer(const myString& fromIBAN, const myString& toIBAN, const double amount)
{
	Account* a1 = nullptr;
	Account* a2 = nullptr;
	for (int i = 0; i < index; i++)
	{
		if (items[i]->GetIBAN() == fromIBAN)
		{
			a1 = items[i];
		}
		if (items[i]->GetIBAN() == toIBAN)
		{
			a2 = items[i];
		}
	}

	if (a1 == nullptr || a2 == nullptr)
	{
		return false;
	}

	if (a1->Withdraw(amount))
	{
		if (!a2->Deposit(amount))
		{
			a1->Deposit(amount);
			return false;
		}

		return true;
	}

	return false;
}

const Account& AccountContainer::operator[](const int i) const
{
	if (i >= index)
	{
		throw "Out of range";
	}

	return *items[i];
}

void AccountContainer::free()
{
	for (int i = 0; i < index; i++)
	{
		delete items[i];
	}
	delete[] items;
}

void AccountContainer::copy(const AccountContainer& other)
{
	index = other.index;
	size = other.size;
	items = new	Account * [size];
	for (int i = 0; i < index; i++)
	{
		items[i] = other.items[i]->clone();
	}
}

void AccountContainer::resize()
{
	Account** temp = new Account * [size *= 2];
	for (int i = 0; i < index; i++)
	{
		temp[i] = items[i];
	}
	delete[] items;
	items = temp;
}