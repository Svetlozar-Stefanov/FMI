#pragma once
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

private:
	char* author;
	unsigned int rating;
};

