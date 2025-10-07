#include <iostream>
#include <fstream>
#include <stdexcept>

#include "FigureCollection.h"

using std::cout;
using std::ofstream;
using std::make_unique;
using std::runtime_error;
using std::out_of_range;

ostream& operator<<(ostream& stream, const FigureCollection& coll)
{
    for (const auto& figure : coll.figures)
    {
        stream << figure->toString() << "\n";
    }

    return stream;
}

void FigureCollection::add(unique_ptr<Figure> figure)
{
    figures.push_back(move(figure));
}

void FigureCollection::duplicate(int index)
{
    if (index < 0 || index >= figures.size())
    {
        throw out_of_range("Index is out of range.\n");
    }
    unique_ptr<Figure> dup = figures[index]->clone();
    figures.push_back(move(dup));
}

void FigureCollection::remove(int index)
{
    if (index < 0 || index >= figures.size())
    {
        throw out_of_range("Index is out of range.\n");
    }
    figures.erase(figures.begin() + index);
}

void FigureCollection::print() const
{
    int i = 0;
    for (const auto& figure : figures)
    {
        cout << i++ <<". " << figure->toString() << "\n";
    }
}

void FigureCollection::saveToFile(const string& filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        throw runtime_error("Unable to save figures in the specified file.");
    }
    file << *this;
    file.close();
}
