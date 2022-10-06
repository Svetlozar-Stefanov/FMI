#pragma once
#include "Dish.h"
#include "IMeatDish.h"

class MeatDish : public IMeatDish, public Dish
{
public:
	MeatDish();
	MeatDish(MeatType meat ,char** ingredients, int count, int cookTime);

	void Print() const override;
	Dish* clone() const override;
};

