#include "SurfAndTurf.h"

SurfAndTurf::SurfAndTurf() : IMeatDish(), ISeafoodDish(), Dish()
{
}

SurfAndTurf::SurfAndTurf(MeatType meat, char* seafood, char** ingredients, int count, int cookTime)
	: IMeatDish(meat), ISeafoodDish(seafood), Dish(ingredients, count, cookTime)
{
}

void SurfAndTurf::Print() const
{
	std::cout << meat << " " << seafood << " " << count << " " << cookTime << '\n';
}

Dish* SurfAndTurf::clone() const
{
	return new SurfAndTurf(*this);
}
