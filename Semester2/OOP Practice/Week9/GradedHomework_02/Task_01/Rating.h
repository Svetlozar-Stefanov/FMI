#pragma once
#include<fstream>

class Rating
{
public:
	Rating();
	Rating(const char* author, const unsigned int rating);
	Rating(const Rating&);
	Rating& operator=(const Rating&);

	const unsigned int GetRatingValue() const;
	const char const* GetAuthor() const;
	void SetRatingValue(const float newRating);
	bool IsCreatedBy(const char* author);

	char* ShowRating();

	friend std::ofstream& operator<<(std::ofstream& file, const Rating&);

private:
	char* author;
	unsigned int rating;
};

