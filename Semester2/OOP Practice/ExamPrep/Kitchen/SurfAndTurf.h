#pragma once
#include "Dish.h"
#include "IMeatDish.h"
#include "ISeafoodDish.h"

class SurfAndTurf : public IMeatDish, public ISeafoodDish, public Dish
{
public:
	SurfAndTurf();
	SurfAndTurf(MeatType meat, char* seafood, char** ingredients, int count, int cookTime);

	void Print() const override;
	Dish* clone() const override;
};

