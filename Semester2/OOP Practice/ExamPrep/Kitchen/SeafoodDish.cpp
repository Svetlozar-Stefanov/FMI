#include "SeafoodDish.h"

SeafoodDish::SeafoodDish()
	: ISeafoodDish(), Dish()
{
}

SeafoodDish::SeafoodDish(char* seafood, char** ingredients, int count, int cookTime)
	: ISeafoodDish(seafood), Dish(ingredients, count, cookTime)
{
}

void SeafoodDish::Print() const
{
	std::cout << "Sea: " << seafood << " " << count << " " << cookTime << '\n';
}

Dish* SeafoodDish::clone() const
{
	return new SeafoodDish(*this);
}
