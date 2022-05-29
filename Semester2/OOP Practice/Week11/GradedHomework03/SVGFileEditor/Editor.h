#pragma once
#include "SVGElement.h"

class Editor
{
private:
	SVGElement** shapes;
	int index, size;

	void free();
	void copy(const Editor& other);
	void resize();

	svgString* parse(const char* str, const char d);
	svgString getInfo(const char* str);
	float stof(const svgString& str);
	
public:
	Editor();
	Editor(const Editor& other);
	Editor& operator=(const Editor& other);
	~Editor();

	void Start();

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
	bool Open(const char* fileName);
	bool Save(const char* fileName) const;
};

