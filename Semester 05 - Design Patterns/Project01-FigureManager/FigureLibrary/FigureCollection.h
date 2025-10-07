#pragma once
#include <vector>
#include <ostream>

#include "Figures/Figure.h"

using std::vector;
using std::ostream;

class FigureCollection
{
private:
	vector<unique_ptr<Figure>> figures;

	friend ostream& operator<<(ostream& stream, const FigureCollection& coll);

public:
	void add(unique_ptr<Figure> figure);

	void duplicate(int index);

	void remove(int index);

	void print() const;

	void saveToFile(const string& filename);
};

