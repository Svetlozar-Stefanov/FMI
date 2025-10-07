#pragma once

#include "FigureFactory.h"

class AbstractFactory
{
public:
	virtual unique_ptr<FigureFactory> createFactory(const string& parameters) const;
};

