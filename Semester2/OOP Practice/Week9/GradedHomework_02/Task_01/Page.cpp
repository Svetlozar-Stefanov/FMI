#include "Page.h";
#include "Functions.h"

Page::Page()
{
	pageNumber = 0;
	content = new char[1];
	content[0] = '\0';
}

Page::Page(const int pageNumber, const char* newContent)
{
	this->pageNumber = pageNumber;
	this->content = copy(newContent);
}

Page::Page(const Page& page)
{
	this->pageNumber = page.pageNumber;
	this->content = page.content;
}

Page& Page::operator=(const Page& page)
{
	this->pageNumber = page.pageNumber;
	this->content = page.content;

	return *this;
}

Page::~Page()
{
	if (content != nullptr)
	{
		delete[] content;
	}
}

char* Page::GetPageContents()
{
	char* pageInx = numToStr(pageNumber);

	char* output = append(pageInx, '\n', content);

	delete pageInx;

	return output;
}

void Page::Edit(const char* newContent)
{
	if (content != nullptr)
	{
		delete content;
	}

	content = copy(newContent);
}
