#include "NormalizeSpaceTransformation.h"
#include "Utils/TextTransformationUtils.h"

using std::string;

NormalizeSpaceTransformation::NormalizeSpaceTransformation()
{
	mType = TransformationType::NORMALIZE_SPACE;
}

string NormalizeSpaceTransformation::transform(string text) const
{
	normalizeBySpace(text);
	return text;
}