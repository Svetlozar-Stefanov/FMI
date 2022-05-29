#pragma once
class Point
{
private:
	float x;
	float y;

public:
	Point();
	Point(const float x, const float y);

	void SetX(const float x);
	void SetY(const float y);

	const float GetX() const;
	const float GetY() const;
};

