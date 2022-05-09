#include "Comment.h"
#include "Functions.h"

Comment::Comment()
{
	author = new char[1];
	author[0] = '\0';
	content = new char[1];
	content[0] = '\0';
}

Comment::Comment(const char* author, const char* comment)
{
	this->author = copy(author);
	this->content = copy(comment);
}

Comment::Comment(const Comment& refComment)
{
	this->author = copy(refComment.author);
	this->content = copy(refComment.content);
}

Comment& Comment::operator=(const Comment& refComment)
{
	this->author = copy(refComment.author);
	this->content = copy(refComment.content);

	return *this;
}

Comment::~Comment()
{
	if (author != nullptr)
	{
		delete[] author;
	}

	if (content != nullptr)
	{
		delete[] content;
	}
}

char const* Comment::GetAuthor() const
{
	return author;
}

char const* Comment::GetRawContent() const
{
	return content;
}

char* Comment::ShowComment()
{
	char* output = append(author,'-', content);

	return output;
}

std::ofstream& operator<<(std::ofstream& file, const Comment& comment)
{
	file << comment.author << '\n';
	file << comment.content << '\n';

	return file;
}
