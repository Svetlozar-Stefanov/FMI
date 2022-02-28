#pragma once

#include "Builder.h"
#include "Type.h"
#include "Wood.h"
#include <string>

class Guitar
{
public:
	Builder GuitarBuilder;
	std::string Model;
	Type GuitarType;

	Wood BackWood;
	Wood TopWood;

	Guitar();
	Guitar(const Builder guitarBuilder, const std::string model, const Type guitarType, const Wood backWood, const Wood topWood);
};
