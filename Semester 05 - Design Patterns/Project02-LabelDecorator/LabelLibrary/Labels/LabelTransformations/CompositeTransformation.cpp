#include "CompositeTransformation.h"

using std::vector;

CompositeTransformation::CompositeTransformation(vector<TextTransformation*> transformations)
{
	mType = TransformationType::COMPOSITE;
	for (int i = 0; i < transformations.size(); i++)
	{
		mTransformations.push_back(transformations[i]);
	}
}

CompositeTransformation::~CompositeTransformation()
{
	for (int i = 0; i < mTransformations.size(); i++)
	{
		if (mTransformations[i] != 0)
		{
			delete mTransformations[i];
		}
	}
	mTransformations.clear();
}

std::string CompositeTransformation::transform(std::string text) const
{
	for (int i = 0; i < mTransformations.size(); i++)
	{
		text = mTransformations[i]->transform(text);
	}
	return text;
}

bool CompositeTransformation::isOfType(TransformationType type) const
{
	for (int i = 0; i < mTransformations.size(); i++)
	{
		if (mTransformations[i]->isOfType(type)) 
		{
			return true;
		}
	}
	return false;
}