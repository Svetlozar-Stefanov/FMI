#include "Rating.h"
#include "Functions.h"

Rating::Rating()
{
	author = new char[1];
	author[0] = '\0';
	rating = 0;
}

Rating::Rating(const char* author, const unsigned int rating)
{
	this->author = copy(author);
	this->rating = rating;
}

Rating::Rating(const Rating& nRat)
{
	this->author = copy(nRat.author);
	this->rating = nRat.rating;
}

Rating& Rating::operator=(const Rating& nRat)
{
	this->author = copy(nRat.author);
	this->rating = nRat.rating;

	return *this;
}

const unsigned int Rating::GetRatingValue() const
{
	return rating;
}

char const* Rating::GetAuthor() const
{
	return author;
}

void Rating::SetRatingValue(const float newRating)
{
	rating = newRating;
}

bool Rating::IsCreatedBy(const char* author)
{
	return compare(this->author, author);
}

char* Rating::ShowRating()
{
	return append(author,'-',numToStr(rating));
}

std::ofstream& operator<<(std::ofstream& file, const Rating& rating)
{
	file << rating.author << ' ';
	file << rating.rating << '\n';

	return file;
}
