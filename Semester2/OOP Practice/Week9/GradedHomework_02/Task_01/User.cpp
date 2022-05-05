#include "User.h"
#include "Functions.h"

User::User()
{
	username = new char[1];
	username[0] = '\0';
	password = -1;
}

User::User(const char* username, const size_t password)
{
	this->username = copy(username);
	this->password = password;
}

User::User(const char* username, const size_t password, const myVector<unsigned int>& readBooks, const myVector<unsigned int>& writtenBooks)
{
	this->username = copy(username);
	this->password = password;
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
	this->password = user.password;
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

bool User::IdentityCompare(const char* username, const size_t password)
{
	if (compare(this->username, username) && this->password == password)
	{
		return true;
	}
	return false;
}

void User::Read(Book book)
{
	currentBook = book;
	currentBook.Open();
}

void User::TurnPage()
{
	currentBook.TurnPage();

	if (currentBook.IsFinished())
	{
		readBooks.Add(currentBook.GetId());
	}
}

void User::TurnBackPage()
{
	currentBook.TurnBackPage();
}

void User::NavigateTo(const unsigned int page)
{
	currentBook.MoveToPage(page);
	if (currentBook.IsFinished())
	{
		readBooks.Add(currentBook.GetId());
	}
}

Book* User::CreateNewBook(const unsigned int id, const char* title, const unsigned int initialPages, myVector<char*>& contents)
{
	Book* newBook = new Book(id, username, title);

	for (int i = 0; i < initialPages; i++)
	{
		newBook->AddPage(contents[i]);
	}

	for (int i = 0; i < initialPages - contents.GetSize(); i++)
	{
		newBook->AddPage();
	}

	return newBook;
}

void User::AddPage(const char* contents, Book * book)
{
	if (!contains(writtenBooks, book->GetId()))
	{
		return;
	}
	book->AddPage(contents);
}

void User::EditPage(const unsigned int num, const char* newContent, Book * book)
{
	if (!contains(writtenBooks, book->GetId()))
	{
		return;
	}

	book->EditPage(num, username, newContent);
}

char* User::ReadComments(const Book& book)
{
	return book.ShowComments();
}

void User::Comment(Book *book, const char* comment)
{
	if(!contains(readBooks, book->GetId()))
	{
		return;
	}

	book->AddComment(username, comment);
}

void User::Rate(Book* book, const unsigned newRating)
{
	if (!contains(readBooks, book->GetId()) || contains(writtenBooks, book->GetId()))
	{
		return;
	}

	book->AddRating(username, newRating);
}

void User::EditRating(Book* book, const unsigned newRating)
{
	if (!contains(readBooks, book->GetId()) || contains(writtenBooks, book->GetId()))
	{
		return;
	}

	book->ChangeRating(username, newRating);
}

char* User::ViewRatings(const Book& book)
{
	return book.ShowRatings();
}
