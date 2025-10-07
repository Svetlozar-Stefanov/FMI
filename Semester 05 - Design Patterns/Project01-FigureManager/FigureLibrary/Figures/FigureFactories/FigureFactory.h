#pragma once
#include <string>

#include "../Figure.h"

using std::string;
using std::unique_ptr;

class FigureFactory
{
public:
	virtual unique_ptr<Figure> createFigure() = 0;
	virtual unique_ptr<Figure> createFigure(const string& parameters);
};

