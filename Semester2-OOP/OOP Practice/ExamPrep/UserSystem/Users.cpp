#include "Users.h"

Users::Users()
{
	cap = 5;
	size = 0;
	users = new IUser * [cap];
	for (int i = 0; i < cap; i++)
	{
		users[i] = nullptr;
	}
}

Users::Users(const Users& other)
{
	copy(other);
}

Users& Users::operator=(const Users& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Users::~Users()
{
	free();
}

void Users::add(const IUser& user)
{
	if (size >= cap)
	{
		resize();
	}
	users[size++] = user.clone();
}

double Users::paidPerc() const
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (users[i]->getType() == Type::PAID)
		{
			count++;
		}
	}
	if (count != 0)
	{
		return (size / count) * 100;
	}
	return 0;
}

double Users::getProfits() const
{
	double profit = 0;
	for (int i = 0; i < size; i++)
	{
		profit += users[i]->getMonthlyProfit();
	}
	return profit;
}

IUser const* Users::getUser(int i)
{
	if (i >= size)
	{
		throw "Out of range";
	}
	return users[i];
}

void Users::copy(const Users& other)
{
	size = other.size;
	cap = other.cap;
	users = new IUser * [cap];
	for (int i = 0; i < size; i++)
	{
		users[i] = other.users[i]->clone();
	}
}

void Users::free()
{
	for (int i = 0; i < size; i++)
	{
		delete users[i];
	}
	delete[] users;
}

void Users::resize()
{
	IUser** temp = new IUser * [cap *= 2];
	for (int i = 0; i < size; i++)
	{
		temp[i] = users[i];
	}

	delete[] users;
	users = temp;
	temp = nullptr;
}
