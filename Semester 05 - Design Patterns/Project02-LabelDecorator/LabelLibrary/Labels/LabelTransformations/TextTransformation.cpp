#include "TextTransformation.h"

TransformationType TextTransformation::getType() const
{
	return mType;
}

bool TextTransformation::isOfType(TransformationType type) const
{
	return mType == type;
}