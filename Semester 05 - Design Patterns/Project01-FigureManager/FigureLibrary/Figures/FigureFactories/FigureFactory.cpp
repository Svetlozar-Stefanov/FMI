#include <sstream>
#include <stdexcept>
#include <memory>

#include "../Triangle.h"
#include "../Circle.h"
#include "../Rectangle.h"
#include "FigureFactory.h"

using std::stringstream;
using std::invalid_argument;
using std::make_unique;

unique_ptr<Figure> FigureFactory::createFigure(const string& parameters)
{
	stringstream sstrm(parameters);
	string figureType;
	sstrm >> figureType;
	if (figureType == "triangle")
	{
		double a, b, c;
		sstrm >> a >> b >> c;
		string temp = sstrm.str();
		if (sstrm.tellg() != -1)
		{
			throw invalid_argument("Invalid number of arguments.");
		}
		return make_unique<Triangle>(a, b, c);
	}
	else if (figureType == "circle")
	{
		double radius;
		sstrm >> radius;
		if (sstrm.tellg() != -1)
		{
			throw invalid_argument("Invalid number of arguments.");
		}
		return make_unique<Circle>(radius);
	}
	else if (figureType == "rectangle")
	{
		double width, height;
		sstrm >> width >> height;
		if (sstrm.tellg() != -1)
		{
			throw invalid_argument("Invalid number of arguments.");
		}
		return make_unique<Rectangle>(width, height);
	}
	
	throw invalid_argument("Invalid figure type.");
}