#include "CensorTransformationFactory.h"

FlyweightCensorTransformation::FlyweightCensorTransformation(TextTransformation* flyweight)
	: mFlyweight(flyweight)
{
	mType = TransformationType::CENSOR;
}

std::string FlyweightCensorTransformation::transform(std::string text) const
{
	return mFlyweight->transform(text);
}

TextTransformation* CensorTransformationFactory::create(const std::string& word)
{
	if (word.length() > 4)
	{
		return new CensorTransformation(word);
	}

	if (mCensorTransformations.find(word) == mCensorTransformations.end())
	{
		mCensorTransformations[word] = new CensorTransformation(word);
	}
	
	return new FlyweightCensorTransformation(mCensorTransformations[word]);
}

CensorTransformationFactory::~CensorTransformationFactory()
{
	for (auto transformation : mCensorTransformations)
	{
		if (transformation.second != nullptr)
		{
			delete transformation.second;
		}
	}
}