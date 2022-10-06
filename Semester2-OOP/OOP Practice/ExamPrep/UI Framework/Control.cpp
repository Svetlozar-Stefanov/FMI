#include "Control.h"

Control::Control()
{
	size = 0;
	origin = Point();
}

Control::Control(double size, Point& origin)
{
	this->size;
	this->origin = origin;
}

const double Control::getSize() const
{
	return size;
}

const Point& Control::getOrigin() const
{
	return origin;
}

void Control::ChangeComponent()
{
	char buffer[100];
	std::cout << "Change: \n";
	std::cin.getline(buffer, 100);
	SetDataDialog(buffer);
}

bool Control::SetDataDialog(char *component)
{
	char buffer[100];
	if (strcmp(component, "size"))
	{
		std::cin.getline(buffer, 100);
		size = atof(buffer);
		return true;
	}
	if (strcmp(component, "origin"))
	{
		std::cin.getline(buffer, 100);
		origin.X = atof(buffer);
		std::cin.getline(buffer, 100);
		origin.Y = atof(buffer);
		return true;
	}
	return false;
}
