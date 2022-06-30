#pragma once
#include "Control.h"

class CheckBox 
	: public Control
{
public:
    CheckBox();
    CheckBox(std::string& label, bool state, double size, Point& origin);

    const std::string& getLabel() const;
    const bool getState() const;

    Control* clone() const override;

protected:
    std::string label;
    bool isOn;

    bool SetDataDialog(char* component) override;
};

