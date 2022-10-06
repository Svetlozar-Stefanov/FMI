#pragma once
#include "Functions.h"
#include <iostream>

const int MAX_INGREDIENTS = 100;

class Dish
{
public:
	Dish();
	Dish(const Dish& other);
	Dish(char** ingredients, int count, int cookTime);
	Dish& operator=(const Dish& other);
	virtual ~Dish();

	virtual void Print() const = 0;
	virtual Dish* clone() const = 0;

protected:
	char** ingredients;
	int count;

	int cookTime;

	void copy(const Dish& other);
	void free();
};
