#pragma once
#include "TextTransformation.h"

#include <string>

class NormalizeSpaceTransformation : public TextTransformation {
public:
	NormalizeSpaceTransformation();
	std::string transform(std::string text) const override;
};