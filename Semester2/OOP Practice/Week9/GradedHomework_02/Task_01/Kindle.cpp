#include "Kindle.h"
#include "Functions.h"
#include <functional>
#include <iostream>
#include <fstream>

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
	readUsers("users.txt");
	readBooks("books.txt");

	std::cout << "~~~~~~~~~~~~~~~~~ Welcome to Kindle ~~~~~~~~~~~~~~~~~\n";

	std::cout << "( signup | login | quit )\n";

	std::cout << ">";
	char input[MAX_INPUT];
	std::cin >> input;
	while (!compare(input,"quit"))
	{
		if (compare(input,"signup"))
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
				loggedInUserInterface();
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
				loggedInUserInterface();
			}
			else
			{
				std::cout << "Login Failed!\n\n";
			}
		}
		else
		{
			std::cout << "Invalid Input!\n";
		}

		std::cout << "( signup | login | quit )\n";

		std::cout << ">";
		std::cin >> input;
	}

	saveUsers("users.txt");
	saveBooks("books.txt");
}

bool Kindle::SignUp(const char* username, const char* password)
{
	if (!isUnique(username))
	{
		return false;
	}

	User* newUser = new User(username, password);

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

	if (user->IdentityCompare(username, password))
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

bool Kindle::WriteComment(const char* bookName, const char* comment)
{
	Book* book = getBook(bookName);
	if (book == nullptr || !currentUser->Comment(book, comment))
	{
		return false;
	}

	return true;
}

bool Kindle::ReadComments(const char* bookName)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	char* output = book->ShowComments();
	if (output == nullptr)
	{
		return false;
	}
	std::cout << output;

	delete[] output;

	return true;
}

bool Kindle::Rate(const char* bookName, const unsigned int rating)
{
	Book* book = getBook(bookName);
	if (book == nullptr || !currentUser->Rate(book, rating))
	{
		return false;
	}

	return true;
}

bool Kindle::ChangeRating(const char* bookName, const unsigned int rating)
{
	Book* book = getBook(bookName);
	if (book == nullptr || !currentUser->EditRating(book, rating))
	{
		return false;
	}

	return true;
}

bool Kindle::ReadRatings(const char* bookName)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	char* output = book->ShowRatings();
	if (output == nullptr)
	{
		return false;
	}
	std::cout << output;

	delete[] output;

	return true;
}

bool Kindle::Write(const char* title, const unsigned int initialPages, myVector<char*>& contents)
{
	if (title == nullptr || initialPages <= 0 || contents.GetSize() < 0)
	{
		return false;
	}

	Book* newBook = currentUser->CreateNewBook(books.GetSize(), title, initialPages, contents);

	if (newBook == nullptr)
	{
		return false;
	}

	books.Add(newBook);

	return true;
}

bool Kindle::AddPage(const char* bookName, const char* contents)
{
	if (bookName == nullptr || contents == nullptr || !currentUser->AddPage(contents, getBook(bookName)))
	{
		return false;
	}

	return true;
}

bool Kindle::EditPage(const char* bookName, const unsigned int pageIndx, const char* contents)
{
	if (bookName == nullptr || pageIndx < 0 || contents == nullptr || !currentUser->EditPage(pageIndx, contents, getBook(bookName)))
	{
		return false;
	}
	
	return true;
}

bool Kindle::Read(const char* bookName)
{
	Book* book = getBook(bookName);
	if (book == nullptr)
	{
		return false;
	}

	char* output = currentUser->Read(book);
	if (output != nullptr)
	{
		std::cout << output;
		delete[] output;
	}
	char input[10];
	do
	{
		std::cin >> input;

		if (compare(input, "n"))
		{
			output = currentUser->TurnPage();
			if (output != nullptr)
			{
				std::cout << output;
				delete[] output;
			}
		}
		else if (compare(input, "p"))
		{
			output = currentUser->TurnBackPage();
			if (output != nullptr)
			{
				std::cout << output;
				delete[] output;
			}
		}
		else if (compare(input, "i"))
		{
			std::cout << ">>";
			unsigned int pageIndx = 0;
			std::cin >> pageIndx;
			pageIndx--;

			output = currentUser->NavigateTo(pageIndx);
			if (output != nullptr)
			{
				std::cout << output;
				delete[] output;
			}
		}
	} while (!compare(input, "q"));
}

void Kindle::saveUsers(const char* fileName)
{
	std::fstream file;
	file.open(fileName, std::fstream::out);

	if (!file.is_open())
	{
		return;
	}

	file << users.GetSize() << '\n';

	for (int i = 0; i < users.GetSize(); i++)
	{
		file << users[i]->GetUsername() << ' ';
		file << users[i]->GetPassword() << ' ';

		myVector<unsigned> *read = users[i]->GetReadBooks();
		file << read->GetSize() << ' ';
		for (int j = 0; j < read->GetSize(); j++)
		{
			file << read->operator[](j) << ' ';
		}

		myVector<unsigned>* written = users[i]->GetWrittenBooks();
		file << written->GetSize() << ' ';
		for (int j = 0; j < written->GetSize(); j++)
		{
			file << written->operator[](j) << ' ';
		}

		file << '\n';
	}
	file.close();
}

void Kindle::saveBooks(const char* fileName)
{
	std::fstream file;
	file.open(fileName, std::fstream::out);

	if (!file.is_open())
	{
		return;
	}

	file << books.GetSize() << '\n';

	for (int i = 0; i < books.GetSize(); i++)
	{
		file << books[i]->GetId() << '\n';
		file << books[i]->GetTitle() << '\n';
		file << books[i]->GetAuthor() << '\n';

		file << '\n';

		myVector<Rating*>* ratings = books[i]->GetRatings();
		file << ratings->GetSize() << '\n';
		for (int j = 0; j < ratings->GetSize(); j++)
		{
			file << ratings->operator[](j)->GetAuthor() << ' ';
			file << ratings->operator[](j)->GetRatingValue() << '\n';
		}

		myVector<Page*>* pages = books[i]->GetPages();
		file << pages->GetSize() << '\n';
		for (int j = 0; j < pages->GetSize(); j++)
		{
			file << pages->operator[](j)->GetRawContent();
			file << "/end_page\n";
			file << pages->operator[](j)->GetPageNumber() << '\n';
		}

		myVector<Comment*>* comments = books[i]->GetComments();
		file << comments->GetSize() << '\n';
		for (int j = 0; j < comments->GetSize(); j++)
		{
			file << comments->operator[](j)->GetAuthor() << '\n';
			file << comments->operator[](j)->GetRawContent() << '\n';
		}

		file << '\n';
	}
	file.close();
}

void Kindle::readUsers(const char* fileName)
{
	std::fstream file;
	file.open(fileName, std::fstream::in);

	if (!file.is_open())
	{
		return;
	}

	int usersCount = 0;
	file >> usersCount;
	for (int i = 0; i < usersCount; i++)
	{
		char username[MAX_INPUT];
		char password[MAX_INPUT];

		file >> username;
		file >> password;

		int read = 0;
		int written = 0;

		myVector<unsigned int> readBooks;
		myVector<unsigned int> writtenBooks;

		file >> read;
		for (int i = 0; i < read; i++)
		{
			unsigned temp = 0;
			file >> temp;
			readBooks.Add(temp);
		}
		file >> written;
		for (int i = 0; i < written; i++)
		{
			unsigned temp = 0;
			file >> temp;
			writtenBooks.Add(temp);
		}

		User* user = new User(username, password, readBooks, writtenBooks);
		users.Add(user);
	}
	
	file.close();
}

void Kindle::readBooks(const char* fileName)
{
	std::fstream file;
	file.open(fileName, std::fstream::in);

	if (!file.is_open())
	{
		return;
	}

	int bookCount = 0;
	file >> bookCount;
	for (int i = 0; i < bookCount; i++)
	{
		unsigned int id = 0;;
		char title[MAX_INPUT];
		char author[MAX_INPUT];

		file >> id;
		file.clear();
		file.ignore(INT_MAX, '\n');
		file.getline(title, MAX_INPUT);
		file.getline(author, MAX_INPUT);
		

		unsigned int rNum = 0;
		unsigned int pNum = 0;
		unsigned int cNum = 0;

		myVector<Rating*> ratings;
		myVector<Page*> pages;
		myVector<Comment*> comments;

		file >> rNum;
		file.clear();
		file.ignore(INT_MAX, '\n');
		for (int i = 0; i < rNum; i++)
		{
			char author[MAX_INPUT];
			unsigned int ratingValue;

			file >> author;
			file >> ratingValue;

			Rating* rating = new Rating(author, ratingValue);

			ratings.Add(rating);
		}

		file >> pNum;
		file.clear();
		file.ignore(INT_MAX, '\n');
		for (int i = 0; i < pNum; i++)
		{
			int j = 0;
			char buffer[MAX_INPUT];
			char page[MAX_INPUT];
			int pageNumber = 0;

			file.getline(buffer, MAX_INPUT);
			while (!compare(buffer, "/end_page"))
			{
				for (int i = 0; i < strleng(buffer); i++)
				{
					if (j < MAX_INPUT - 1)
					{
						page[j++] = buffer[i];
					}
				}
				page[j++] = '\n';

				file.getline(buffer, MAX_INPUT);
			}
			page[j] = '\0';

			file >> pageNumber;
			file.clear();
			file.ignore(INT_MAX, '\n');

			Page* newPage = new Page(pageNumber, page);
			pages.Add(newPage);
		}

		file >> cNum;
		file.clear();
		file.ignore(INT_MAX, '\n');
		for (int i = 0; i < cNum; i++)
		{
			char author[MAX_INPUT];
			char content[MAX_INPUT];

			file >> author;
			file.clear();
			file.ignore(INT_MAX, '\n');
			file.getline(content, MAX_INPUT);

			Comment* comment = new Comment(author, content);

			comments.Add(comment);
		}

		Book* book = new Book(id, title, author, ratings, pages, comments);
		books.Add(book);
	}

	file.close();
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
		if (compare(users[i]->GetUsername(), username))
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
		if (compare(books[i]->GetTitle(), title))
		{
			return books[i];
		}
	}

	return nullptr;
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
	std::cout << "( read | write | add_page | add_pages | edit_page | write_comment | read_comments | rate | change_rating | view_ratings | logout )\n";
	std::cout << ">";
	char input[MAX_INPUT];
	std::cin >> input;

	while (!compare(input, "logout"))
	{
		if (compare(input, "read"))
		{
			char title[MAX_INPUT];
			std::cout << "Enter book name: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			if (!Read(title))
			{
				std::cout << "Invalid Input!\n";
			}
		}
		else if (compare(input, "write"))
		{
			char title[MAX_INPUT];
			unsigned int numberOfPages = 0;

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			std::cout << "Enter number of pages: ";
			std::cin >> numberOfPages;

			myVector<char*>* pages = getPages(numberOfPages);

			if (pages == nullptr || !Write(title, numberOfPages, *pages))
			{
				std::cout << "Invalid Content!\n";
			}
			else
			{
				std::cout << "Book added added successfuly!\n";
				delete pages;
			}
		}
		else if (compare(input, "add_page"))
		{
			char title[MAX_INPUT];

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			char* content = getPage();
			if (content == nullptr || !AddPage(title, content))
			{
				std::cout << "Invalid Input!\n";
			}
		}
		else if (compare(input, "add_pages"))
		{
			char title[MAX_INPUT];
			unsigned int numberOfPages = 0;

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			std::cout << "Enter number of pages: ";
			std::cin >> numberOfPages;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			for (int i = 0; i < numberOfPages; i++)
			{
				if (!AddPage(title, getPage()))
				{
					std::cout << "Invalid Input!\n";
				}
			}
		}
		else if (compare(input, "edit_page"))
		{
			char title[MAX_INPUT];
			unsigned int pageIndx = 0;

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			std::cout << "Enter page number: ";
			std::cin >> pageIndx;
			pageIndx--;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			char* page = getPage();
			if (page == nullptr || !EditPage(title, pageIndx, page))
			{
				std::cout << "Invalid Input!\n";
			}
		}
		else if (compare(input, "write_comment"))
		{
			char title[MAX_INPUT];

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			char comment[MAX_INPUT];
			std::cout << "Enter comment: ";
			std::cin.getline(comment, MAX_INPUT);

			if (!WriteComment(title, comment))
			{
				std::cout << "Invalid Input!\n";
			}
		}
		else if (compare(input, "read_comments"))
		{
			char title[MAX_INPUT];

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);


			if (!ReadComments(title))
			{
				std::cout << "Invalid Input!\n";
			}
		}
		else if (compare(input, "rate"))
		{
			char title[MAX_INPUT];

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			unsigned int rating = 0;
			std::cout << "Enter rating: ";
			std::cin >> rating;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			if (!Rate(title, rating))
			{
				std::cout << "Invalid Input!\n";
			}
		}
		else if (compare(input, "change_rating"))
		{
			char title[MAX_INPUT];

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);

			unsigned int rating = 0;
			std::cout << "Enter new rating: ";
			std::cin >> rating;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');

			if (!ChangeRating(title, rating))
			{
				std::cout << "Invalid Input!\n";
			}
		}
		else if (compare(input, "view_ratings"))
		{
			char title[MAX_INPUT];

			std::cout << "Enter title: ";
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			std::cin.getline(title, MAX_INPUT);


			if (!ReadRatings(title))
			{
				std::cout << "Invalid Input!\n";
			}
		}


		std::cout << "( read | write | add_page | add_pages | edit_page | write_comment | read_comment | rate | change_rating | view_ratings | logout )\n";
		std::cout << ">";
		std::cin >> input;
	}
}

char* Kindle::getPage()
{
	int indx = 0;
	char* pageContent = new char[MAX_INPUT];
	char temp[MAX_INPUT];


	std::cout << "start page: \n";
	std::cin.getline(temp, MAX_INPUT);

	while (!compare(temp, "/end_page"))
	{
		for (int i = 0; i < strleng(temp); i++)
		{
			if (indx < MAX_INPUT)
			{
				pageContent[indx++] = temp[i];
			}
			else
			{
				break;
			}
		}

		if (indx < MAX_INPUT)
		{
			pageContent[indx++] = '\n';
		}

		std::cin.getline(temp, MAX_INPUT);
	}

	if (indx < MAX_INPUT)
	{
		pageContent[indx] = '\0';
	}
	else
	{
		pageContent[MAX_INPUT - 1] = '\0';
	}

	return pageContent;
}

myVector<char*>* Kindle::getPages(const unsigned int numberOfPages)
{
	std::cin.ignore(INT_MAX, '\n');

	myVector<char*>* pages = new myVector<char*>();
	for (int i = 0; i < numberOfPages; i++)
	{
		pages->Add(getPage());
	}

	return pages;
}
