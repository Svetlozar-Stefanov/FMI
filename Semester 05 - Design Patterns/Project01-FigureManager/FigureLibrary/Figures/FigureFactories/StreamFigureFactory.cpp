#include <string.h>
#include <fstream>
#include <memory>
#include <stdexcept>

#include "StreamFigureFactory.h"

using std::invalid_argument;
using std::runtime_error;

StreamFigureFactory::StreamFigureFactory(istream& inputStream)
	: mInputStream(inputStream) {}

StreamFigureFactory::StreamFigureFactory(ifstream&& inputStream)
	: fileStream(move(inputStream)), mInputStream(fileStream) 
{
	if (!fileStream.is_open())
	{
		throw invalid_argument("Invalid file stream passed.");
	}
}

unique_ptr<Figure> StreamFigureFactory::createFigure()
{
	string input;
	if (!getline(mInputStream, input))
	{
		throw runtime_error("Cannot read after end of file.");
	}
	
	return FigureFactory::createFigure(input);
}