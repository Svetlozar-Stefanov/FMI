#pragma once
#include "BaseDecorator.h"

class Decorator : public BaseDecorator {
private:
	TextTransformation* mTransformation;
public:
	Decorator(Label* decorated, TextTransformation* transformation);
	Decorator(const Decorator& other) = delete;
	Decorator& operator=(const Decorator& other) = delete;
	virtual ~Decorator() override;

	std::string getText() const override;
	Label* removeDecorator(TransformationType transformationToRemove) override;
};