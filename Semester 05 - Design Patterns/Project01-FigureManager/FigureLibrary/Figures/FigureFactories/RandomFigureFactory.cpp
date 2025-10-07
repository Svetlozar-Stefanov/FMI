#include <random>
#include <memory>
#include <stdexcept>

#include "RandomFigureFactory.h"
#include "../Triangle.h"
#include "../Circle.h"
#include "../Rectangle.h"

using std::make_unique;
using std::runtime_error;

RandomFigureFactory::RandomFigureFactory(uint32_t seed)
{
	rng.seed(seed);
	shapeDistrib = uniform_int_distribution<int>(0, NUMBER_OF_SHAPES - 1);
	sideDistrib = uniform_real_distribution<double>(0.000001, std::numeric_limits<double>::max());
}

unique_ptr<Figure> RandomFigureFactory::createFigure()
{
	Figures figure = (Figures)shapeDistrib(rng);
	switch (figure)
	{
		case TRIANGLE:
		{
			double a = 0, b = 0, c = 0;
			while (a >= c + b || b >= a + c || c >= a + b)
			{
				a = sideDistrib(rng);
				b = sideDistrib(rng);
				c = sideDistrib(rng);
			}
			return make_unique<Triangle>(a, b, c);
		}
		case CIRCLE:
		{
			double r = sideDistrib(rng);
			return make_unique<Circle>(r);
		}
		case RECTANGLE:
		{
			double width = sideDistrib(rng);
			double height = sideDistrib(rng);
			return make_unique<Rectangle>(width, height);
		}
		default:
			throw runtime_error("Unexpected error: tried to create non existant figure.");
	}
}
