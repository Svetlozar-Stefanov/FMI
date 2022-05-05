#pragma once
#include "Book.h"
#include "myVector.h"

class User
{
public:
	User();
	User(const char* username, const size_t password);
	User(const char* username, const size_t password, const myVector<unsigned int> &readBooks, const myVector<unsigned int> &writtenBooks);
	User(const User&);
	User& operator=(const User&);
	~User();

	const char const* GetUsername() const;
	
	bool IdentityCompare(const char* username, const size_t password);

	void Read(Book book);
	void TurnPage();
	void TurnBackPage();
	void NavigateTo(const unsigned int page);

	Book* CreateNewBook(const unsigned int id, const char* title, const unsigned int initialPages, myVector<char*> &contents);
	void AddPage(const char* contents, Book *book);
	void EditPage(const unsigned int num, const char* newContent, Book *book);
	
	//void Close();

	char* ReadComments(const Book& book);
	void Comment(Book *book, const char * comment);

	void Rate(Book *book, const unsigned newRating);
	void EditRating(Book *book, const unsigned newRating);
	char* ViewRatings(const Book& book);

private:
	char* username;
	size_t password;
	myVector<unsigned int> readBooks;
	myVector<unsigned int> writtenBooks;
	Book currentBook;
};

