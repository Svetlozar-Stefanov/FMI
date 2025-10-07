#pragma once
#include "Labels/Label.h"
#include "Labels/LabelTransformations/TextTransformation.h"

#include <typeinfo>

class BaseDecorator : public Label {
protected:
	Label* mDecorated;
public:
	BaseDecorator(Label* decorated);
	BaseDecorator(const BaseDecorator& other) = delete;
	BaseDecorator& operator=(const BaseDecorator& other) = delete;

	static Label* removeDecoratorFrom(Label* label, TransformationType transformationToRemove);
	virtual Label* removeDecorator(TransformationType transformationToRemove) = 0;
};