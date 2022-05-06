#include "User.h"
#include "Functions.h"

User::User()
{
	username = new char[1];
	username[0] = '\0';
	password = new char[1];
	password[0] = '\0';
}

User::User(const char* username, const char* password)
{
	this->username = copy(username);
	this->password = copy(password);
}

User::User(const char* username, const char* password, const myVector<unsigned int>& readBooks, const myVector<unsigned int>& writtenBooks)
{
	this->username = copy(username);
	this->password = copy(password);
	this->readBooks = readBooks;
	this->writtenBooks = writtenBooks;
}

User::User(const User& user)
{
	this->username = user.username;
	this->password = user.password;
	this->readBooks = user.readBooks;
	this->writtenBooks = user.writtenBooks;
}

User& User::operator=(const User& user)
{
	this->username = copy(user.username);
	this->password = copy(user.password);
	this->readBooks = user.readBooks;
	this->writtenBooks = user.writtenBooks;

	return *this;
}

User::~User()
{
	if (username != nullptr)
	{
		delete[] username;
	}
}

const char const* User::GetUsername() const
{
	return username;
}

char const* User::GetPassword() const
{
	return password;
}

myVector<unsigned int>* User::GetReadBooks()
{
	return &readBooks;
}

myVector<unsigned int>* User::GetWrittenBooks()
{
	return &writtenBooks;
}

bool User::IdentityCompare(const char* username, const char * password)
{
	if (compare(this->username, username) && compare(this->password, password))
	{
		return true;
	}
	return false;
}

char* User::Read(Book* book)
{
	currentBook = book;
	if (currentBook->IsFinished() && !contains(readBooks, currentBook->GetId()))
	{
		readBooks.Add(currentBook->GetId());
	}
	return currentBook->Open();
}

char* User::TurnPage()
{
	char * page = currentBook->TurnPage();

	if (page != nullptr && currentBook->IsFinished() && !contains(readBooks, currentBook->GetId()))
	{
		readBooks.Add(currentBook->GetId());
	}

	return page;
}

char* User::TurnBackPage()
{
	return currentBook->TurnBackPage();
}

char * User::NavigateTo(const unsigned int page)
{
	char * pageContents = currentBook->MoveToPage(page);
	if (pageContents != nullptr && currentBook->IsFinished() && !contains(readBooks, currentBook->GetId()))
	{
		readBooks.Add(currentBook->GetId());
	}
	return pageContents;
}

Book* User::CreateNewBook(const unsigned int id, const char* title, const unsigned int initialPages, myVector<char*>& contents)
{
	Book* newBook = new Book(id, title, username);

	for (int i = 0; i < initialPages; i++)
	{
		newBook->AddPage(contents[i]);
	}

	for (int i = 0; i < initialPages - contents.GetSize(); i++)
	{
		newBook->AddPage();
	}

	writtenBooks.Add(newBook->GetId());

	return newBook;
}

bool User::AddPage(const char* contents, Book * book)
{
	if (book == nullptr)
	{
		return false;
	}

	if (!contains(writtenBooks, book->GetId()))
	{
		return false;
	}
	book->AddPage(contents);

	return true;
}

bool User::EditPage(const unsigned int num, const char* newContent, Book* book)
{
	if (newContent == nullptr || book == nullptr)
	{
		return false;
	}

	if (!contains(writtenBooks, book->GetId()))
	{
		return false;
	}

	book->EditPage(num, username, newContent);

	return true;
}

char* User::ReadComments(const Book& book)
{
	return book.ShowComments();
}

bool User::Comment(Book *book, const char* comment)
{
	if(!contains(readBooks, book->GetId()) || contains(writtenBooks, book->GetId()))
	{
		return false;
	}

	book->AddComment(username, comment);

	return true;
}

bool User::Rate(Book* book, const unsigned newRating)
{
	if (!contains(readBooks, book->GetId()) || contains(writtenBooks, book->GetId()))
	{
		return false;
	}

	book->AddRating(username, newRating);
	return true;
}

bool User::EditRating(Book* book, const unsigned newRating)
{
	if (!contains(readBooks, book->GetId()) || contains(writtenBooks, book->GetId()))
	{
		return false;
	}

	book->ChangeRating(username, newRating);

	return true;
}

char* User::ViewRatings(const Book& book)
{
	return book.ShowRatings();
}
