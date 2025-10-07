#pragma once
#include "TextTransformation.h"

#include <vector>

class CompositeTransformation : public TextTransformation {
private:
	std::vector<TextTransformation*> mTransformations;
public:
	CompositeTransformation(std::vector<TextTransformation*> transformations);
	~CompositeTransformation() override;

	std::string transform(std::string text) const override;
	bool isOfType(TransformationType type) const override;
};