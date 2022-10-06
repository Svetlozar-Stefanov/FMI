#pragma once
#include "insufficient_fuel_error.h"

class FuelTank
{
public:
	FuelTank(double capacity);

	void Use(double amount);
	void Fill(double amount);

private:
	double size;
	double capacity;
};

