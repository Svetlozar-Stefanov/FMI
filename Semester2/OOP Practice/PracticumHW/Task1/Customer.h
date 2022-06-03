#pragma once
#include "myString.h"

class Customer
{
public:
	Customer();
	Customer(const int id, const myString& name, const myString& address);

	unsigned GetID() const;
	const myString& GetName() const;
	const myString& GetAdress() const;

	void SetID(const int id);
	void SetName(const myString& name);
	void SetAddress(const myString& address);

	void print() const;

private:
	int id;
	myString name;
	myString address;
};

