#include "Car.h"

Car::Car(double tankCap, int hp, const unsigned engineId, const char* engineManufacturer, const char* engineDescription, double width, int profile, double diameter, const unsigned tireId, const char* tireManufacturer, const char* tireDescription, int capacity, const char* model, const unsigned batteryId, const char* batteryManufacturer, const char* batteryDescription, double weight)
	: tank(tankCap)
{
	engine = new Engine(hp, engineId, engineManufacturer, engineDescription);
	for (int i = 0; i < 4; i++)
	{
		tires[i] = new Tire(width, profile, diameter, tireId, tireManufacturer, tireDescription);
	}
	battery = new Battery(capacity, model, batteryId, batteryManufacturer, batteryDescription);
	milage = 0;
	this->weight = weight;
}

Car::Car(const Car& other) : tank(other.tank)
{
	copy(other);
}

Car& Car::operator=(const Car& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Car::~Car()
{
	free();
}

const FuelTank& Car::getTank()
{
	return tank;
}

void Car::drive(double kms)
{
	try
	{
		tank.Use(kms);
	}
	catch (insufficient_fuel_error)
	{
		throw insufficient_fuel_error("Not Enough Fuel To Drive");
		return;
	}
	milage += kms;
}

void Car::copy(const Car& other)
{
	tank = other.tank;
	engine = new Engine(other.engine->GetHP(), other.engine->GetID(), other.engine->GetManufacturer(), other.engine->GetDescription());
	for (int i = 0; i < 4; i++)
	{
		tires[i] = new Tire(other.tires[0]->GetWidth(), other.tires[0]->GetProfile(), other.tires[0]->GetDiameter()
			, other.tires[0]->GetID(), other.tires[0]->GetManufacturer(), other.tires[0]->GetDescription());
	}
	battery = new Battery(other.battery->GetCapacity(), other.battery->GetModel(), 
		other.battery->GetID(), other.battery->GetManufacturer(), other.battery->GetDescription());
	milage = 0;
	this->weight = other.weight;
	this->milage = other.milage;
}

void Car::free()
{
	delete engine;
	for (int i = 0; i < 4; i++)
	{
		delete tires[i];
	}
	delete battery;
}

Car* dragRace(Car* car1, Car* car2)
{
	bool car1HasFuel = true;
	bool car2HasFuel = true;
	try
	{
		car1->drive(0.4);
	}
	catch (insufficient_fuel_error)
	{
		car1HasFuel = false;
	}
	try
	{
		car2->drive(0.4);
	}
	catch (insufficient_fuel_error)
	{
		car2HasFuel = false;
	}
	if (car1HasFuel && car2HasFuel)
	{
		return (car1->weight / car1->engine->GetHP()) > (car2->weight / car2->engine->GetHP()) ? car1 : car2;
	}
	if (car1HasFuel)
	{
		return car1;
	}
	if (car2HasFuel)
	{
		return car2;
	}
	return nullptr;
}
