#include "Dish.h"

Dish::Dish()
{
	ingredients = new char* [MAX_INGREDIENTS];
	for (int i = 0; i < MAX_INGREDIENTS; i++)
	{
		ingredients[i] = nullptr;
	}
	count = 0;
	cookTime = 0;
}

Dish::Dish(const Dish& other)
{
	copy(other);
}

Dish::Dish(char** ingredients, int count, int cookTime)
{
	this->count = count;
	this->ingredients = new char* [MAX_INGREDIENTS];
	for (int i = 0; i < count; i++)
	{
		scopy(this->ingredients[i], ingredients[i]);
	}
	this->cookTime = cookTime;
}

Dish& Dish::operator=(const Dish& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Dish::~Dish()
{
	free();
}

void Dish::copy(const Dish& other)
{
	count = other.count;
	ingredients = new char* [MAX_INGREDIENTS];
	for (int i = 0; i < count; i++)
	{
		scopy(ingredients[i], other.ingredients[i]);
	}
	cookTime = other.cookTime;
}

void Dish::free()
{
	for (int i = 0; i < count; i++)
	{
		delete[] ingredients;
	}
	delete[] ingredients;
}
