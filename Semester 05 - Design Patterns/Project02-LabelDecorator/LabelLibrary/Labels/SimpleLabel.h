#pragma once
#include "Label.h"

#include <string>

class SimpleLabel : public Label {
public:
	std::string mValue;

	SimpleLabel(const std::string& value);

	std::string getText() const override;
};