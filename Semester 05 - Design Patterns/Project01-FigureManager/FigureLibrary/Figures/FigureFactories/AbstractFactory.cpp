#include <sstream>
#include <iostream>
#include <fstream>
#include <memory>

#include "AbstractFactory.h"
#include "RandomFigureFactory.h"
#include "StreamFigureFactory.h"

using std::stringstream;
using std::cin;
using std::ifstream;
using std::invalid_argument;
using std::runtime_error;
using std::make_unique;
using std::move;
using std::shared_ptr;
using std::make_shared;

unique_ptr<FigureFactory> AbstractFactory::createFactory(const string& parameters) const
{
	stringstream sstrm(parameters);
	string type;
	sstrm >> type;

	if (type == "random")
	{
		return make_unique<RandomFigureFactory>(time(nullptr));
	}
	else if (type == "stdin")
	{
		return make_unique<StreamFigureFactory>(cin);
	}
	else if (type == "file")
	{
		string filename;
		sstrm >> filename;

		 ifstream file(filename);

		return make_unique<StreamFigureFactory>(move(file));
	}
	
	throw invalid_argument("Invalid factory type.");
}
