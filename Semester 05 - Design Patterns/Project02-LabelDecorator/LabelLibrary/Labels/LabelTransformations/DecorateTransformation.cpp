#include "DecorateTransformation.h"

DecorateTransformation::DecorateTransformation()
{
	mType = TransformationType::DECORATE;
}

std::string DecorateTransformation::transform(std::string text) const
{
	return "-={ " + text + " }=-";
}