#pragma once
#include <fstream>
#include "SVGElement.h"

class Editor
{
private:
	SVGElement** shapes;
	int index, size;

	void free();
	void copy(const Editor& other);
	void resize();

	friend std::fstream& operator<<(std::fstream& s, const Editor& editor);
	friend std::fstream& operator>>(std::fstream& s, const Editor& editor);
	
public:
	Editor();
	Editor(const Editor& other);
	Editor& operator=(const Editor& other);
	~Editor();

	void Print() const;
	bool Create(const SVGElement& newEl);
	bool Erase(const int i);
	bool Translate(const float horiz, const float vert);
	bool Translate(const int i, const float horiz, const float vert);
	void IsWithin(const float x, const float y, const float width, const float height) const ;
	void IsWithin(const float x, const float y, const float r) const;
	void PointIn(const float x, const float y) const;
	void Areas() const;
	void Pers() const;
};

