#pragma once
class Page
{
public:
	Page();
	Page(const int pageNumber, const char* newContent);
	Page(const Page&);
	Page& operator=(const Page&);
	~Page();

	char* GetPageContents();
	void Edit(const char * newContent);

private:
	unsigned pageNumber;
	char* content;
};

