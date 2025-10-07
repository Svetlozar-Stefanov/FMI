#pragma once
#include "TextTransformation.h"

#include <string>

class CapitalizeTransformation : public TextTransformation {
public:
	CapitalizeTransformation();
	std::string transform(std::string text) const override;
};