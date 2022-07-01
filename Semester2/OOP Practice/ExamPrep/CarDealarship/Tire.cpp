#include "Tire.h"

Tire::Tire(double width, int profile, double diameter, const unsigned id, const char* manufacturer, const char* description)
	: CarPart(id, manufacturer, description)
{
	this->width = width;
	this->profile = profile;
	this->diameter = diameter;
}

const double Tire::GetWidth() const
{
	return width;
}

const int Tire::GetProfile() const
{
	return profile;
}

const double Tire::GetDiameter() const
{
	return diameter;
}

std::ostream& Tire::operator<<(std::ostream& os)
{
	os << this;
	os << " - " << width << '/' << profile << "R" << diameter << '\n';
	return os;
}
