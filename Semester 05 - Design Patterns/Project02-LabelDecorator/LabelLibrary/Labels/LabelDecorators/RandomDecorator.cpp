#include "RandomDecorator.h"

#include <stdexcept>

using std::string;
using std::vector;

using std::mt19937;
using std::uniform_int_distribution;

using std::invalid_argument;

RandomDecorator::RandomDecorator(Label* decorated, vector<TextTransformation*> transformations, unsigned int seed)
	: BaseDecorator(decorated)
{
	for (int i = 0; i < transformations.size(); i++) 
	{
		mTransformations.push_back(transformations[i]);
	}

	rng = new mt19937(seed);
	dist = new uniform_int_distribution<unsigned int>(0, mTransformations.size()-1);
}

RandomDecorator::~RandomDecorator()
{
	if (mDecorated != nullptr) 
	{
		delete mDecorated;
	}
	if (rng != nullptr)
	{
		delete rng;
	}
	if (dist != nullptr)
	{
		delete dist;
	}
	for (int i = 0; i < mTransformations.size(); i++)
	{
		if (mTransformations[i] != 0)
		{
			delete mTransformations[i];
		}
	}
	mTransformations.clear();
}

string RandomDecorator::getText() const
{
	return mTransformations[(*dist)(*rng)]->transform(mDecorated->getText());
}

Label* RandomDecorator::removeDecorator(TransformationType transformationToRemove)
{
	for (TextTransformation* transformation : mTransformations) {
		if (transformation->isOfType(transformationToRemove))
		{
			Label* decoratedCopy = mDecorated;
			this->mDecorated = nullptr;
			delete this;
			return decoratedCopy;
		}
	}

	BaseDecorator* decorated = dynamic_cast<BaseDecorator*>(mDecorated);
	if (decorated != nullptr)
	{
		mDecorated = decorated->removeDecorator(transformationToRemove);
		return this;
	}
	else
	{
		throw invalid_argument("There is no such decorator applied to the label.");
	}
}