#pragma once
#include "Book.h"
#include "myVector.h"

class User
{
public:
	User();
	User(const char* username, const char* password);
	User(const char* username, const char* password, const myVector<unsigned int> &readBooks, const myVector<unsigned int> &writtenBooks);
	User(const User&);
	User& operator=(const User&);
	~User();

	const char const* GetUsername() const;
	const char const* GetPassword() const;
	 myVector<unsigned int>* GetReadBooks();
	 myVector<unsigned int>* GetWrittenBooks();
	
	bool IdentityCompare(const char* username, const char* password);

	char* Read(Book* book);
	char* TurnPage();
	char* TurnBackPage();
	char* NavigateTo(const unsigned int page);

	Book* CreateNewBook(const unsigned int id, const char* title, const unsigned int initialPages, myVector<char*> &contents);
	bool AddPage(const char* contents, Book *book);
	bool EditPage(const unsigned int num, const char* newContent, Book *book);

	char* ReadComments(const Book& book);
	bool Comment(Book *book, const char * comment);

	bool Rate(Book *book, const unsigned newRating);
	bool EditRating(Book *book, const unsigned newRating);
	char* ViewRatings(const Book& book);

private:
	char* username;
	char* password;
	myVector<unsigned int> readBooks;
	myVector<unsigned int> writtenBooks;
	Book *currentBook;
};

