#pragma once
#include <random>

#include "FigureFactory.h"

using std::mt19937;
using std::uniform_real_distribution;
using std::uniform_int_distribution;

const int NUMBER_OF_SHAPES = 3;

enum Figures
{
	TRIANGLE,
	CIRCLE,
	RECTANGLE
};

class RandomFigureFactory : public FigureFactory
{
private:
	mt19937 rng;
	uniform_int_distribution<int> shapeDistrib;
	uniform_real_distribution<double> sideDistrib;
public:
	RandomFigureFactory(uint32_t seed);
	virtual unique_ptr<Figure> createFigure() override;
};

