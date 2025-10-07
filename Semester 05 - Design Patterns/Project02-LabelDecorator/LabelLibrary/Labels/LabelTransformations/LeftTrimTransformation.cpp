#include "LeftTrimTransformation.h"
#include "Utils/TextTransformationUtils.h"

LeftTrimTransformation::LeftTrimTransformation()
{
	mType = TransformationType::LEFT_TRIM;
}

std::string LeftTrimTransformation::transform(std::string text) const
{
	ltrim(text);
	return text;
}