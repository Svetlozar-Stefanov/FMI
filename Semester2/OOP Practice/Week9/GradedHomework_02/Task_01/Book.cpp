#include "Book.h"
#include "Functions.h"

Book::Book()
{
	id = 0;
	title = new char[1];
	title[0] = '\0';
	author = new char[1];
	title[0] = '\0';
}

Book::Book(const unsigned int id, const char* title, const char* author,
	 myVector<Rating*> &ratings, myVector<Page*> &pages,  myVector<Comment*> &comments)
{
	this->id = id;
	this->title = copy(title);
	this->author = copy(author);
	this->ratings = ratings;
	this->pages = pages;
	this->pageIndx = 0;
	this->comments = comments;
}

Book::Book(const unsigned int id, const char* title, const char* author)
{
	this->id = id;
	this->title = copy(title);
	this->author = copy(author);
	this->pageIndx = 0;
}

Book::Book(const Book& book)
{
	this->id = book.id;
	this->title = book.title;
	this->author = book.author;
	this->ratings = book.ratings;
	this->pages = book.pages;
	this->pageIndx = 0;
	this->comments = book.comments;
}

Book& Book::operator=(const Book& book)
{
	this->id = book.id;
	this->title = copy(book.title);
	this->author = copy(book.author);
	this->ratings = book.ratings;
	this->pages = book.pages;
	this->pageIndx = 0;
	this->comments = book.comments;

	return *this;
}

Book::~Book()
{
	if (title != nullptr)
	{
		delete[] title;
	}
	if (author != nullptr)
	{
		delete[] author;
	}
}

unsigned int Book::GetId() const
{
	return id;
}

char const* Book::GetTitle() const
{
	return title;
}

char* Book::displayPage()
{
	char* pageContents = nullptr;
	if (pageIndx >= 0 && pageIndx < pages.GetSize())
	{
		pageContents = pages[pageIndx]->GetPageContents();
	}

	return pageContents;
}

const float Book::GetRating()
{
	float avgRating = 0.0f;
	for (int i = 0; i < ratings.GetSize(); i++)
	{
		avgRating += ratings[i]->GetRatingValue();
	}

	if (ratings.GetSize() > 0)
	{
		avgRating /= ratings.GetSize();
	}
	return avgRating;
}

const bool Book::IsFinished()
{
	return (pageIndx + 1 == pages.GetSize());
}

char* Book::Open()
{
	pageIndx = 0;

	char* page = displayPage();

	char* output = append(title, '\n', "By - ");
	char* temp = output;
	output = append(output, author);
	delete temp;
	temp = output;
	output = append(output, '\n', page);
	delete temp;
	delete page;

	return output;
}

char* Book::TurnPage()
{
	if (pageIndx >= 0 && pageIndx < pages.GetSize())
	{
		pageIndx++;
		return displayPage();
	}
}

char* Book::TurnBackPage()
{
	if (pageIndx >= 0 && pageIndx < pages.GetSize())
	{
		pageIndx--;
		return displayPage();
	}
}

char* Book::MoveToPage(const unsigned pageNumber)
{
	if (pageNumber >= 0 && pageNumber < pages.GetSize())
	{
		pageIndx = pageNumber;
		return displayPage();
	}
}

void Book::AddPage()
{
	Page* newPage = new Page(pages.GetSize(), "\0");
	pages.Add(newPage);
}

void Book::AddPage(const char* content)
{
	Page* newPage = new Page(pages.GetSize(), content);
	pages.Add(newPage);
}

bool Book::EditPage(const unsigned int num, const char* user, const char* newContent)
{
	if (!compare(user, author))
	{
		return false;
	}

	pages[num]->Edit(newContent);

	return true;
}

void Book::AddComment(const char* author, const char* content)
{
	if (author == nullptr || content == nullptr)
	{
		return;
	}

	Comment* newComment = new Comment(author, content);

	comments.Add(newComment);
}

char* Book::ShowComments() const
{
	if (comments.GetSize() < 0)
	{
		return nullptr;
	}
	char* output = comments[0]->ShowComment();
	for (int i = 1; i < comments.GetSize(); i++)
	{
		char* temp = output;
		output = append(output, '\n', comments[i]->ShowComment());
		delete[] temp;
	}

	return output;
}

void Book::AddRating(const char* author, const unsigned int rating)
{
	if (rating < 0 || rating > 10)
	{
		return;
	}

	Rating* newRatings = new Rating(author, rating);

	ratings.Add(newRatings);
}

char* Book::ShowRatings() const
{
	if (ratings.GetSize() < 0)
	{
		return nullptr;
	}
	char* output = append("Avg -", ratings[0]->ShowRating());
	for (int i = 1; i < ratings.GetSize(); i++)
	{
		char* temp = output;
		output = append(output, '\n', ratings[i]->ShowRating());
		delete[] temp;
	}

	return output;
}

void Book::ChangeRating(const char* author, const unsigned int newRating)
{
	for (int i = 0; i < ratings.GetSize(); i++)
	{
		if (ratings[i]->IsCreatedBy(author))
		{
			ratings[i]->SetRatingValue(newRating);
		}
	}
}