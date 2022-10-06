#include "CarPart.h"

void CarPart::copy(const CarPart& other)
{
	id = other.id;
	manufacturer = new char[strlen(other.manufacturer)];
	strcpy(manufacturer, other.manufacturer);
	description = new char[strlen(other.description)];
	strcpy(description, other.description);
}

void CarPart::free()
{
	delete[] manufacturer;
	delete[] description;
}

CarPart::CarPart(const unsigned id, const char* manufacturer, const char* description)
{
	this->id = id;
	this->manufacturer = new char[strlen(manufacturer)];
	strcpy(this->manufacturer, manufacturer);
	this->description = new char[strlen(description)];
	strcpy(this->description, description);
}

CarPart::CarPart(const CarPart& other)
{
	copy(other);
}

CarPart& CarPart::operator=(const CarPart& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

CarPart::~CarPart()
{
	free();
}

const unsigned CarPart::GetID() const
{
	return id;
}

char const* CarPart::GetManufacturer() const
{
	return manufacturer;
}

char const* CarPart::GetDescription() const
{
	return description;
}

std::ostream& CarPart::operator<<(std::ostream& os)
{
	os << id << "by" << manufacturer << "-" << description;
	return os;
}
