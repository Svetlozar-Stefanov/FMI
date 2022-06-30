#include "MeatDish.h"

MeatDish::MeatDish()
	: IMeatDish(), Dish()
{
}

MeatDish::MeatDish(MeatType meat, char** ingredients, int count, int cookTime)
	: IMeatDish(meat), Dish(ingredients, count, cookTime)
{
}

void MeatDish::Print() const
{
	std::cout << "MeatDish info: " << meat << " " << count << " " << cookTime << "\n";
}

Dish* MeatDish::clone() const
{
	return new MeatDish(*this);
}
