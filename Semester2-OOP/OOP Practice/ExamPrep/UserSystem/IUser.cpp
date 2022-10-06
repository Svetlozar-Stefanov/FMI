#include "IUser.h"
#pragma warning(disable: 4996)

IUser::IUser(const char* name, const char* pass)
{
	this->name = new char[strlen(name)];
	this->pass = new char[strlen(pass)];
	strcpy(this->name, name);
	strcpy(this->pass, pass);
}

IUser::IUser(const IUser& other)
{
	copy(other);
}

IUser& IUser::operator=(const IUser& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

IUser::~IUser()
{
	free();
}

char const* IUser::getName() const
{
	return name;
}

const Type IUser::getType() const
{
	return type;
}

void IUser::copy(const IUser& other)
{
	this->name = new char[strlen(other.name)];
	this->pass = new char[strlen(other.pass)];
	strcpy(this->name, other.name);
	strcpy(this->pass, other.pass);
}

void IUser::free()
{
	delete[] name;
	delete[] pass;
}
