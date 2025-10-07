#include "BaseDecorator.h"

#include <stdexcept>

using std::type_info;
using std::invalid_argument;

BaseDecorator::BaseDecorator(Label* decorated)
	: mDecorated(decorated)
{}

Label* BaseDecorator::removeDecoratorFrom(Label* label, TransformationType transformationToRemove)
{
	if (label == nullptr)
	{
		throw invalid_argument("Invalid label. Cannot remove decorator from nullptr.");
	}

	BaseDecorator* decorator = dynamic_cast<BaseDecorator*>(label);
	if (decorator != nullptr)
	{
		return decorator->removeDecorator(transformationToRemove);
	}
	else
	{
		throw invalid_argument("There is no such decorator applied to the label.");
	}
}