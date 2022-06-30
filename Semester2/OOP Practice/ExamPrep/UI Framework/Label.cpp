#include "Label.h"

Label::Label()
	: Control()
{
	label = std::string();
}

Label::Label(std::string& label, double size, Point& origin)
	: Control(size, origin)
{
	this->label = label;
}

const std::string& Label::getLabel() const
{
	return label;
}

Control* Label::clone() const
{
    return new Label(*this);
}

bool Label::SetDataDialog(char* component)
{
	char buffer[100];
	if (Control::SetDataDialog(component))
	{
		return true;
	}
	if (strcmp(component, "label"))
	{
		std::cin.getline(buffer, 100);
		label = buffer;
		return true;
	}
	return false;
}
