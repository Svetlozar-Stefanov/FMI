#pragma once
#include <cstring>

enum Type
{
	PAID,
	FREE
};

class IUser
{
public:
	IUser(const char* name, const char* pass);
	IUser(const IUser& other);
	IUser& operator=(const IUser& other);
	~IUser();

	const char const* getName() const;
	const Type getType() const;

	virtual double getMonthlyProfit() const = 0;
	virtual IUser* clone() const = 0;

protected:
	char* name;
	char* pass;
	Type type;
private:
	void copy(const IUser& other);
	void free();
};

