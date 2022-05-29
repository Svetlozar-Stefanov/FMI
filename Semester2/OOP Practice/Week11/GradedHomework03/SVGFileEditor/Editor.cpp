#include "Editor.h"

void Editor::free()
{
	for (int i = 0; i < size; i++)
	{
		delete shapes[i];
	}

	delete[] shapes;
}

void Editor::copy(const Editor& other)
{
	size = other.size;
	index = other.index;

	shapes = new SVGElement * [size];

	for (int i = 0; i < size; i++)
	{
		shapes[i] = other.shapes[i]->clone();
	}
}

void Editor::resize()
{
	SVGElement** temp = new SVGElement * [size *= 2];
	for (int i = 0; i < index; i++)
	{
		temp[i] = shapes[i];
	}

	delete[] shapes;
	shapes = temp;
	temp = nullptr;
}

Editor::Editor()
{
	size = 5;
	index = 0;
	shapes = new SVGElement * [size];
}

Editor::Editor(const Editor& other)
{
	copy(other);
}

Editor& Editor::operator=(const Editor& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Editor::~Editor()
{
	free();
}

void Editor::Print() const
{
	for (int i = 0; i < index; i++)
	{
		std::cout << i << ". " << shapes[i]->GetInfo();
	}
}

bool Editor::Create(const SVGElement& newEl)
{
	if (index >= size)
	{
		resize();
	}

	shapes[index] = newEl.clone();

	return true;
}

bool Editor::Erase(const int i)
{
	if (i >= index)
	{
		return false;
	}

	delete shapes[i];
	shapes[i] = nullptr;

	return true;
}

bool Editor::Translate(const float horiz, const float vert)
{
	for (int i = 0; i < index; i++)
	{
		shapes[i]->Translate(horiz, vert);
	}

	return true;
}

bool Editor::Translate(const int i, const float horiz, const float vert)
{
	if (i >= index)
	{
		return false;
	}

	shapes[i]->Translate(horiz, vert);
}

void Editor::IsWithin(const float x, const float y, const float width, const float height) const
{
	for (int i = 0; i < index; i++)
	{
		if (shapes[i]->IsWithinRegion(x, y, width, height))
		{
			std::cout << "Shape N. " << i << " " << shapes[i]->GetInfo();
		}
	}
}

void Editor::IsWithin(const float x, const float y, const float r) const
{
	for (int i = 0; i < index; i++)
	{
		if (shapes[i]->IsWithinRegion(x, y, r))
		{
			std::cout << "Shape N. " << i << " " << shapes[i]->GetInfo();
		}
	}
}

void Editor::PointIn(const float x, const float y) const
{
	for (int i = 0; i < index; i++)
	{
		if (shapes[i]->ContainsPoint(x, y))
		{
			std::cout << "Shape N. " << i << " " << shapes[i]->GetInfo();
		}
	}
}

void Editor::Areas() const
{
	for (int i = 0; i < index; i++)
	{
		std::cout << "Shape N. " << i << " " << shapes[i]->GetArea();
	}
}

void Editor::Pers() const
{
	for (int i = 0; i < index; i++)
	{
		std::cout << "Shape N. " << i << " " << shapes[i]->GetPerimeter();
	}
}
