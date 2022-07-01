#include "Battery.h"

Battery::Battery(int capacity, const char* model, const unsigned id, const char* manufacturer, const char* description)
	: CarPart(id, manufacturer, description)
{
	this->capacity;
	this->model = new char[strlen(model)];
	strcpy(this->model, model);
}

Battery::Battery(const Battery& other) : CarPart(other)
{
	copy(other);
}

Battery& Battery::operator=(const Battery& other)
{
	if (this != &other)
	{
		free();
		copy(other);
		CarPart::operator=(other);
	}
	return *this;
}

Battery::~Battery()
{
	free();
}

const int Battery::GetCapacity() const
{
	return capacity;
}

char const* Battery::GetModel() const
{
	return model;
}

std::ostream& Battery::operator<<(std::ostream& os)
{
	os << this;
	os << " - " << capacity << "Ah" << '\n';
	return os;
}

void Battery::copy(const Battery& other)
{
	model = new char[strlen(other.model)];
	strcpy(manufacturer, other.model);
}

void Battery::free()
{
	delete[] model;
}
