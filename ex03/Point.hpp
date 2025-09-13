#pragma once

#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(const float xValue, const float yValue);
	Point(const Point &other);

	Point &operator=(const Point &other);

	~Point();

	Fixed getX() const;
	Fixed getY() const;
};