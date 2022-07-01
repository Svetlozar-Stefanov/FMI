#pragma once
#include "FuelTank.h"
#include "Engine.h"
#include "Tire.h"
#include "Battery.h"

class Car
{
public:
	Car(double tankCap,
		int hp, const unsigned engineId, const char* engineManufacturer, const char* engineDescription,
		double width, int profile, double diameter,
		const unsigned tireId, const char* tireManufacturer, const char* tireDescription,
		int capacity, const char* model, const unsigned batteryId, const char* batteryManufacturer, const char* batteryDescription,
		double weight);
	Car(const Car& other);
	Car& operator=(const Car& other);
	~Car();

	const FuelTank& getTank();

	void drive(double kms);

	friend Car* dragRace(Car* car1, Car* car2);

private:
	FuelTank tank;
	Engine* engine;
	Tire* tires[4];
	Battery* battery;

	double milage;
	double weight;
	void copy(const Car& other);
	void free();
};

Car* dragRace(Car* car1, Car* car2);

