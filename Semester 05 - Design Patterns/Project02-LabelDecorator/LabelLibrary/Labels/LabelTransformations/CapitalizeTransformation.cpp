#include "CapitalizeTransformation.h"

CapitalizeTransformation::CapitalizeTransformation()
{
	mType = TransformationType::CAPITALIZE;
}

std::string CapitalizeTransformation::transform(std::string text) const
{
	if (text.size() > 0 && isalpha(text[0]))
	{
		text[0] = toupper(text[0]);
	}

	return text;
}