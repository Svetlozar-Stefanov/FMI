#pragma once
#include "BaseDecorator.h"
#include "Labels/LabelTransformations/TextTransformation.h"

#include <vector>
#include <random>

class RandomDecorator : public BaseDecorator {
private:
	std::vector<TextTransformation*> mTransformations;

	std::mt19937* rng;
	std::uniform_int_distribution<unsigned int>* dist;
public:
	RandomDecorator(Label* decorated, std::vector<TextTransformation*> transformations, unsigned int seed);
	RandomDecorator(const RandomDecorator& other) = delete;
	RandomDecorator& operator=(const RandomDecorator& other) = delete;
	~RandomDecorator() override;

	std::string getText() const override;
	Label* removeDecorator(TransformationType transformationToRemove) override;
};