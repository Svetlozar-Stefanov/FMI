#include "Kindle.h"
#include "Functions.h"
#include <functional>
#include <iostream>

const int MAX_INPUT = 1024;
const unsigned int AVG_PARSE_WORD_LEN = 20;

Kindle::Kindle()
{
	currentUser = nullptr;
}

Kindle::~Kindle()
{

}

void Kindle::Start()
{
	std::cout << "~~~~~~~~~~~~~~~~~ Welcome to Kindle ~~~~~~~~~~~~~~~~~\n";

	std::cout << "( signup | login | quit )\n";

	std::cout << ">";
	char input[MAX_INPUT];
	std::cin >> input;
	while (!compare(input, "quit"))
	{
		if (compare(input, "signup"))
		{
			char username[MAX_INPUT];
			char password[MAX_INPUT];
			std::cout << "Enter Username: ";
			std::cin >> username;
			std::cout << "Enter Password: ";
			std::cin >> password;

			if (SignUp(username, password))
			{
				std::cout << "Registration Successful!\n\n";
			}
			else
			{
				std::cout << "Registration Failed!\n\n";
			}
		}
		else if (compare(input, "login"))
		{
			char username[MAX_INPUT];
			char password[MAX_INPUT];
			std::cout << "Enter Username: ";
			std::cin >> username;
			std::cout << "Enter Password: ";
			std::cin >> password;

			if (Login(username, password))
			{
				std::cout << "Login Successful!\n\n";
			}
			else
			{
				std::cout << "Login Failed!\n\n";
			}
		}
		std::cin >> input;
	}
}

bool Kindle::SignUp(const char* username, const char* password)
{
	if (!isUnique(username))
	{
		return false;
	}

	std::hash<char*> passHash;

	User* newUser = new User(username, passHash(copy(password)));

	users.Add(newUser);
	currentUser = newUser;

	return true;
}

bool Kindle::isUnique(const char* username)
{
	return !contains(username);
}

bool Kindle::Login(const char* username, const char* password)
{
	User* user = getUser(username);
	if (user == nullptr)
	{
		return false;
	}

	std::hash<char*> passHash;

	if (user->IdentityCompare(username, passHash(copy(password))))
	{
		currentUser = user;
		return true;
	}

	return false;
}

void Kindle::View()
{
	for (int i = 0; i < books.GetSize(); i++)
	{
		std::cout << '\t' << i + 1 << ". " << books[i]->GetTitle() << '\n';
	}
}

bool Kindle::Comment(const char* bookName, const char* comment)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	currentUser->Comment(book, comment);

	return true;
}

bool Kindle::ReadComments(const char* bookName)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	std::cout << book->ShowComments();
}

bool Kindle::Rate(const char* bookName, const unsigned int rating)
{
	Book* book = getBook(bookName);
	if (book = nullptr)
	{
		return false;
	}

	currentUser->Rate(book, rating);

	return true;
}

bool Kindle::ChangeRating(const char* bookName, const unsigned int rating)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	currentUser->EditRating(book, rating);

	return true;
}

bool Kindle::ReadRatings(const char* bookName)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	std::cout << book->ShowRatings();

	return true;
}

bool Kindle::Write(const char* title, const unsigned int initialPages, myVector<char*>& contents)
{
	if (title == nullptr || initialPages <= 0 || contents.GetSize() < 0)
	{
		return false;
	}

	currentUser->CreateNewBook(books.GetSize(), title, initialPages, contents);

	return true;
}

bool Kindle::AddPage(const char* bookName, const char* contents)
{
	if (bookName == nullptr || contents == nullptr)
	{
		return false;
	}

	currentUser->AddPage(contents, getBook(bookName));
	return true;
}

bool Kindle::EditPage(const char* bookName, const unsigned int pageIndx, const char* contents)
{
	if (bookName == nullptr || pageIndx < 0 || contents == nullptr)
	{
		return false;
	}

	currentUser->EditPage(pageIndx, contents, getBook(bookName));

	return true;
}

bool Kindle::Read(const char* bookName)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	currentUser->Read(*book);
	char input[10];
	do
	{
		std::cin.getline(input, 10);
		myVector<char*> data = *parse(input, ' ', AVG_PARSE_WORD_LEN);

		if (input == "n")
		{
			currentUser->TurnPage();
		}
		else if (input == "p")
		{
			currentUser->TurnBackPage();
		}
		else if (data.GetSize() > 1 && compare(data[0], "i"))
		{
			unsigned int pageIndx = strToNum(data[1]);

			currentUser->NavigateTo(pageIndx);
		}
	} while (input != "q");
}

bool Kindle::contains(const char* username)
{
	for (int i = 0; i < users.GetSize(); i++)
	{
		if (users[i]->GetUsername() == username)
		{
			return true;
		}
	}

	return false;
}

User* Kindle::getUser(const char* username)
{
	for (int i = 0; i < users.GetSize(); i++)
	{
		if (users[i]->GetUsername() == username)
		{
			return users[i];
		}
	}

	return nullptr;
}

Book* Kindle::getBook(const char* title)
{
	for (int i = 0; i < books.GetSize(); i++)
	{
		if (books[i]->GetTitle() == title)
		{
			return books[i];
		}
	}
}

unsigned int Kindle::getBookId(const char* title)
{
	for (int i = 0; i < books.GetSize(); i++)
	{
		if (books[i]->GetTitle() == title)
		{
			return books[i]->GetId();
		}
	}
}

void Kindle::loggedInUserInterface()
{
	std::cout << "( read | write | add_page | edit_page | write_comment | read_comment | rate | change_rating | view_ratings | logout )\n";
	char input[MAX_INPUT];
	std::cin >> input;
}
