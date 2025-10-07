#pragma once
#include <istream>

#include "FigureFactory.h"

using std::istream;
using std::shared_ptr;
using std::ifstream;

class StreamFigureFactory : public FigureFactory
{
private:
	ifstream fileStream;
	istream& mInputStream;
public:
	StreamFigureFactory(istream& inputStream);
	StreamFigureFactory(ifstream&& inputStream);

	StreamFigureFactory(const StreamFigureFactory& other) = delete;
	StreamFigureFactory& operator=(const StreamFigureFactory& other) = delete;

	virtual unique_ptr<Figure> createFigure() override;
};

