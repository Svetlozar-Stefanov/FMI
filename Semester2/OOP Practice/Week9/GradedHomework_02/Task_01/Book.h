#pragma once
#include "Comment.h";
#include "Page.h";
#include "Rating.h"
#include "myVector.h"

class Book
{
public:
	Book();

	Book(const unsigned int id, const char* title, const char* author,
		myVector<Rating*>& ratings, myVector<Page*>& pages, myVector<Comment*>& comments);

	Book(const unsigned int id, const char* title, const char* author);

	Book(const Book& book);
	Book& operator=(const Book& book);
	~Book();

	unsigned int GetId() const;
	const char const* GetTitle() const; 
	const char const* GetAuthor() const;
	const float GetRating();

	const bool IsFinished();

	char* Open();

	char* TurnPage();
	char* TurnBackPage();
	char* MoveToPage(const unsigned pageNumber);

	void AddPage();
	void AddPage(const char * content);
	bool EditPage(const unsigned int num, const char* user, const char* newContent);
	
	void AddComment(const char* author, const char* content);
	char* ShowComments() const;

	void AddRating(const char* author, const unsigned int rating);
	char* ShowRatings() const;
	void ChangeRating(const char* author, const unsigned int newRating);

private:
	unsigned int id;
	char* title;
	char* author;
	myVector<Rating*> ratings;
	myVector<Page*> pages;
	unsigned int pageIndx;
	myVector<Comment*> comments;
	
	char* displayPage();
};

