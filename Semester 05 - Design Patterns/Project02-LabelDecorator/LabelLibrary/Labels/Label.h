#pragma once
#include <string>

class Label {
public:
	virtual ~Label() {};

	virtual std::string getText() const = 0;
};