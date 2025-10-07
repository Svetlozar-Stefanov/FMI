#pragma once
#include "CensorTransformation.h"
#include <unordered_map>

class FlyweightCensorTransformation : public TextTransformation {
private:
	TextTransformation* mFlyweight;
public:
	FlyweightCensorTransformation(TextTransformation* flyweight);
	std::string transform(std::string text) const override;
};

class CensorTransformationFactory {
private:
	std::unordered_map<std::string, TextTransformation*> mCensorTransformations;

public:
	TextTransformation* create(const std::string& word);
	~CensorTransformationFactory();
};