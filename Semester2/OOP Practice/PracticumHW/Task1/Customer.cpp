#include "Customer.h"

Customer::Customer()
{
	id = -1;
}

Customer::Customer(const int id, const myString& name, const myString& address)
{
	this->id = id;
	this->name = name;
	this->address = address;
}

unsigned Customer::GetID() const
{
	return id;
}

const myString& Customer::GetName() const
{
	return name;
}

const myString& Customer::GetAdress() const
{
	return address;
}

void Customer::SetID(const int id)
{
	this->id = id;
}

void Customer::SetName(const myString& name)
{
	this->name = name;
}

void Customer::SetAddress(const myString& address)
{
	this->address = address;
}

void Customer::print() const
{
	std::cout << id << " Name: " << name << " Address: " << address << '\n';
}
