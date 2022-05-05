#pragma once
#include "User.h"
#include "Book.h"

class Kindle
{
public:
	Kindle();
	~Kindle();

	void Start();

	bool SignUp(const char* username, const char * password);

	bool Login(const char * username, const char * password);

	void View();

	bool Comment(const char * bookName, const char * comment);
	bool ReadComments(const char * bookName);

	bool Rate(const char * bookName, const unsigned int rating);
	bool ChangeRating(const char * bookName, const unsigned int rating);
	bool ReadRatings(const char * bookName);

	bool Write(const char* title, const unsigned int initialPages, myVector<char*>& contents);
	bool AddPage(const char * bookName, const char * contents);
	bool EditPage(const char* bookName, const unsigned int pageIndx, const char * contents);

	bool Read(const char * bookName);


private:
	myVector<Book*> books;
	myVector<User*> users;

	User* currentUser;

	myVector<User*> readUsers(const char * fileName);
	myVector<Book*> readBooks();

	bool contains(const char* username);
	bool isUnique(const char* username);
	User* getUser(const char* username);
	Book* getBook(const char* title);
	unsigned int getBookId(const char* title);

	void loggedInUserInterface();
};

