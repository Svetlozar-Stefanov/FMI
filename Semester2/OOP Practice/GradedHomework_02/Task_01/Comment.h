#pragma once
#include <fstream>

class Comment
{
public:
	Comment();
	Comment(const char* author, const char* comment);
	Comment(const Comment&);
	Comment& operator=(const Comment&);
	~Comment();

	const char const* GetAuthor() const;
	const char const* GetRawContent() const;

	char* ShowComment();

	friend std::ofstream& operator<<(std::ofstream& file, const Comment&);
private:
	char* author;
	char* content;
};

