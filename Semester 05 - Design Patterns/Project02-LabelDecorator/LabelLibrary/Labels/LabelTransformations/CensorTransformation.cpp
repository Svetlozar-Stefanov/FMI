#include "CensorTransformation.h"

#include "Utils/TextTransformationUtils.h"

using std::string;

CensorTransformation::CensorTransformation(const string& word)
	:mWord(word)
{
	mType = TransformationType::CENSOR;
	mReplacement = string(mWord.size(), '*');
}

std::string CensorTransformation::transform(string text) const
{
	replace(text, mWord, mReplacement);
	return text;
}