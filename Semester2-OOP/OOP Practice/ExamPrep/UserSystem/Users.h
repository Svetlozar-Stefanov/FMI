#pragma once
#include "IUser.h"
class Users
{
public:
	Users();
	Users(const Users& other);
	Users& operator=(const Users& other);
	~Users();

	void add(const IUser& user);
	double paidPerc() const;
	double getProfits() const;

	const IUser const* getUser(int i);

private:
	IUser** users;
	int size, cap;

	void copy(const Users& other);
	void free();
	void resize();
};

