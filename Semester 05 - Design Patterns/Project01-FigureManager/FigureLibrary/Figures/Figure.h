#pragma once
#include <string>
#include <memory>

using std::string;
using std::unique_ptr;

class Figure {
public:
	virtual double getPerimeter() const = 0;

	virtual unique_ptr<Figure> clone() const = 0;

	virtual string toString() const = 0;
};