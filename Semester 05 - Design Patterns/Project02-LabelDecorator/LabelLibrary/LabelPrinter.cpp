#include "LabelPrinter.h";

#include <iostream>

void LabelPrinter::print(const Label& label)
{
	std::cout << "Here is a label: " << label.getText() << '\n';
}

void LabelPrinter::printWithHelpText(const HelpLabel& label)
{
	print(label);
	std::cout << "With help text: " << label.getHelperText() << '\n';
}