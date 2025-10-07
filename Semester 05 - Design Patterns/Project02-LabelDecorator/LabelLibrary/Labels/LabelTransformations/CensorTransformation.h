#pragma once
#include "TextTransformation.h"

#include <string>

class CensorTransformation : public TextTransformation {
private:
	std::string mWord;
	std::string mReplacement;
public:
	CensorTransformation(const std::string& word);

	std::string transform(std::string text) const override;
};