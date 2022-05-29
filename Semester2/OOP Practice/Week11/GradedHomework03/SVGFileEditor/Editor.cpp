#include "Editor.h"
#include "Line.h"
#include "Rectangle.h"
#include "Circle.h"

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

svgString* Editor::parse(const char* str, const char d)
{
	svgString* info = new svgString[10];
	int indx = 0;
	for (int i = 0; i < strleng(str); i++)
	{
		if (str[i] == d)
		{
			indx++;
		}

		info[indx] += str[i];
	}

	return info;
}

svgString Editor::getInfo(const char* str)
{
	int size = strleng(str);
	bool started = false;

	svgString out;
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '\"' && !started);
		{
			started = true;
			continue;
		}

		if (str[i] == '\"' && started);
		{
			started = false;
			continue;
		}

		if (started)
		{
			out += str[i];
		}

	}

	return out;
}

float Editor::stof(const svgString& str)
{
	int num = 0;
	int comma = -1;
	for (int i = 0; i < str.GetLength(); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			num += str[i] - '0';
			num *= 10;
		}
		if (str[i] == ',')
		{
			comma = i;
		}
	}

	if (comma != -1)
	{
		return num / pow(10, dCount(num) - comma);
	}

	return num;
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

void Editor::Start()
{
	char input[1024];
	std::cin.getline(input, 1024);
	while (strcomp(input, "quit"))
	{
		svgString* info = parse(input, ' ');
		if (info[0] == "open")
		{
			Open(info[1].GetRaw());
		}
		else if (info[0] == "create")
		{
			if (info[1] == "line")
			{
				float x1 = stof(info[2]);
				float y1 = stof(info[3]);
				float x2 = stof(info[4]);
				float y2 = stof(info[5]);

				Line line(x1, y1, x2, y2, info[6]);
				Create(line);
			}
			if (info[1] == "rect")
			{
				float x = stof(info[2]);
				float y = stof(info[3]);
				float width = stof(info[4]);
				float height = stof(info[5]);

				Rectangle rect(x, y, width, height, info[6]);
				Create(rect);
			}
			if (info[1] == "circle")
			{
				float x = stof(info[2]);
				float y = stof(info[3]);
				float r = stof(info[4]);

				Circle circ(x, y, r, info[5]);
				Create(circ);
			}
		}
		else if (info[0] == "erase")
		{
			int index = (int)stof(info[1]);

			Erase(index);
		}
		else if (info[0] == "translate_all")
		{
			float horiz = stof(info[1]);
			float vert = stof(info[2]);

			Translate(horiz, vert);
		}
		else if (info[0] == "translate")
		{
			int index = (int)stof(info[1]);
			float horiz = stof(info[2]);
			float vert = stof(info[3]);

			Translate(index, horiz, vert);
		}
		else if (info[0] == "within_rec")
		{
			float x = stof(info[1]);
			float y = stof(info[2]);
			float width = stof(info[3]);
			float height = stof(info[4]);

			IsWithin(x, y, width, height);
		}
		else if (info[0] == "within_circ")
		{
			float x = stof(info[1]);
			float y = stof(info[2]);
			float r = stof(info[3]);

			IsWithin(x, y, r);
		}
		else if (info[0] == "pointin")
		{
			float x = stof(info[1]);
			float y = stof(info[2]);

			PointIn(x, y);
		}
		else if (info[0] == "areas")
		{
			Areas();
		}
		else if (info[0] == "pers")
		{
			Pers();
		}

		delete[] info;

		char input[1024];
		std::cin.getline(input, 1024);
	}
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

bool Editor::Open(const char* fileName)
{
	std::fstream file(fileName, std::fstream::in);
	if (!file.is_open())
	{
		return false;
	}

	char current[1024];
	while (!file.eof())
	{
		file >> current;
		if (strcomp(current, "<svg>"))
		{
			continue;
		}

		if (strcomp(current, "<line"))
		{
			float x1, y1, x2, y2;
			svgString fill;
			svgString temp;

			file >> current;
			temp = getInfo(current);
			x1 = stof(temp);

			file >> current;
			temp = getInfo(current);
			y1 = stof(temp);

			file >> current;
			temp = getInfo(current);
			x2 = stof(temp);

			file >> current;
			temp = getInfo(current);
			y2 = stof(temp);

			file >> current;
			fill = current;

			Line line(x1, y1, x2, y2, fill);
			Create(line);
		}
		else if (strcomp(current, "<rect"))
		{
			float x, y, width, height;
			svgString fill;
			svgString temp;

			file >> current;
			temp = getInfo(current);
			x = stof(temp);

			file >> current;
			temp = getInfo(current);
			y = stof(temp);

			file >> current;
			temp = getInfo(current);
			width = stof(temp);

			file >> current;
			temp = getInfo(current);
			height = stof(temp);

			file >> current;
			fill = current;

			Rectangle rect(x, y, width, height, fill);
			Create(rect);
		}
		else if (strcomp(current, "<circle"))
		{
			float x, y, r;
			svgString fill;
			svgString temp;

			file >> current;
			temp = getInfo(current);
			x = stof(temp);

			file >> current;
			temp = getInfo(current);
			y = stof(temp);

			file >> current;
			temp = getInfo(current);
			r = stof(temp);

			file >> current;
			fill = current;

			Circle circle(x, y, r, fill);
			Create(circle);
		}
	}
}

bool Editor::Save(const char* fileName) const
{
	std::fstream file(fileName, std::fstream::out);
	if (!file.is_open())
	{
		return false;
	}

	file << "<svg>\n";
	for (int i = 0; i < index; i++)
	{
		file << shapes[i];
	}
	file << "</svg>\n";

	return false;
}
