#include "Guitar.h"

Guitar::Guitar()
{
}

Guitar::Guitar(Builder guitarBuilder, std::string model, Type guitarType, Wood backWood, Wood topWood)
{
	GuitarBuilder = guitarBuilder;
	Model = model;
	GuitarType = guitarType;
	BackWood = backWood;
	TopWood = topWood;
}
