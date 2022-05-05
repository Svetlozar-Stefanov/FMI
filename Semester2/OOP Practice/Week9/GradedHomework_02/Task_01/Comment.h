#pragma once
class Comment
{
public:
	Comment();
	Comment(const char* author, const char* comment);
	Comment(const Comment&);
	Comment& operator=(const Comment&);
	~Comment();

	char* ShowComment();
private:
	char* author;
	char* content;
};

