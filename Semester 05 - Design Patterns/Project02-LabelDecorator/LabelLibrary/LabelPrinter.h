#pragma once
#include "Labels/Label.h"
#include "Labels/HelpLabel.h"

class LabelPrinter
{
public:
	static void print(const Label& label);
	static void printWithHelpText(const HelpLabel& label);
};

