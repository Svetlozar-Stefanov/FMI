#pragma once
#include<fstream>

class Page
{
public:
	Page();
	Page(const int pageNumber, const char* newContent);
	Page(const Page&);
	Page& operator=(const Page&);
	~Page();

	const char const* GetRawContent() const;
	const unsigned GetPageNumber() const;

	char* GetPageContents();
	void Edit(const char * newContent);

	friend std::ofstream& operator<<(std::ofstream& file, const Page&);

private:
	unsigned pageNumber;
	char* content;
};

