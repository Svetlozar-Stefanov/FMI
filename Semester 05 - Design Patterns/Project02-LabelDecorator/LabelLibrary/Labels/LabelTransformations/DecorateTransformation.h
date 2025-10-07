#pragma once
#include "TextTransformation.h"

#include <string>

class DecorateTransformation : public TextTransformation {
public:
	DecorateTransformation();
	std::string transform(std::string text) const override;
};