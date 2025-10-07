#include "ReplaceTransformation.h"
#include "Utils/TextTransformationUtils.h"

using std::string;

ReplaceTransformation::ReplaceTransformation(const string& toReplace, const string& replacement)
	: mToReplace(toReplace), mReplacement(replacement)
{
	mType = TransformationType::REPLACE;
}

std::string ReplaceTransformation::transform(std::string text) const
{
	replace(text, mToReplace, mReplacement);
	return text;
}