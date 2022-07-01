#include "FuelTank.h"

FuelTank::FuelTank(double capacity)
{
	this->capacity = capacity;
	this->size = capacity;
}

void FuelTank::Use(double amount)
{
	if (amount > size)
	{
		throw insufficient_fuel_error(std::string("Not enough fuel"));
		return;
	}

}

void FuelTank::Fill(double amount)
{
	size += amount;
	if (size > capacity)
	{
		size = capacity;
	}
}
