#pragma once
#include "Control.h"
#include <string>

class Label :
    public Control
{
public:
    Label();
    Label(std::string& label, double size, Point& origin);

    const std::string& getLabel() const;

    Control* clone() const override;

protected:
    std::string label;

    bool SetDataDialog(char* component) override;
};

