#include "ISeafoodDish.h"

void ISeafoodDish::copy(const ISeafoodDish& other)
{
	scopy(seafood, other.seafood);
}

void ISeafoodDish::free()
{
	delete[] seafood;
}

ISeafoodDish::ISeafoodDish()
{
	seafood = new char[1];
	seafood[0] = '\0';
}

ISeafoodDish::ISeafoodDish(char* seafood)
{
	scopy(this->seafood, seafood);
}

ISeafoodDish::ISeafoodDish(const ISeafoodDish& other)
{
	copy(other);
}

ISeafoodDish& ISeafoodDish::operator=(const ISeafoodDish& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

ISeafoodDish::~ISeafoodDish()
{
	free();
}
