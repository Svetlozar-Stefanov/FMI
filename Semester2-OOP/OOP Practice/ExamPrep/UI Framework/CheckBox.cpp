#include "CheckBox.h"

CheckBox::CheckBox()
	: Control()
{
	label = std::string();
	isOn = false;
}

CheckBox::CheckBox(std::string& label, bool state, double size, Point& origin)
	: Control(size, origin)
{
	this->label = label;
	isOn = state;
}

const std::string& CheckBox::getLabel() const
{
	return label;	
}

const bool CheckBox::getState() const
{
	return isOn;
}

Control* CheckBox::clone() const
{
    return new CheckBox(*this);
}

bool CheckBox::SetDataDialog(char* component)
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
	if (strcmp(component, "check"))
	{
		isOn = !isOn;
		return true;
	}

    return false;
}
