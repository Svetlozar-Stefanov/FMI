#include "RightTrimTransformation.h"
#include "Utils/TextTransformationUtils.h"

using std::string;

RightTrimTransformation::RightTrimTransformation()
{
	mType = TransformationType::RIGHT_TRIM;
}

string RightTrimTransformation::transform(string text) const
{
	rtrim(text);
	return text;
}