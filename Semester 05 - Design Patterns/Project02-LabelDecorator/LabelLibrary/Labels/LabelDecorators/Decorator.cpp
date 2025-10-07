#include "Decorator.h"

#include <stdexcept>
#include <type_traits>

#include <iostream>

using std::string;
using std::invalid_argument;
using std::is_convertible;

Decorator::Decorator(Label* decorated, TextTransformation* transformation)
	: BaseDecorator(decorated), mTransformation(transformation)
{}

Decorator::~Decorator()
{
	if (mDecorated != nullptr)
	{
		delete mDecorated;
	}
	if (mTransformation != nullptr)
	{
		delete mTransformation;
	}
}

string Decorator::getText() const
{
	return mTransformation->transform(mDecorated->getText());
}

Label* Decorator::removeDecorator(TransformationType transformationToRemove)
{
	if (mTransformation->isOfType(transformationToRemove))
	{
		Label* decoratedCopy = mDecorated;
		this->mDecorated = nullptr;
		delete this;
		return decoratedCopy;
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