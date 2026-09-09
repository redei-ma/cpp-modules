#include "Point.hpp"

Point::Point() :x(0), y(0)
{}

Point::Point(float const x, float const y) :x(x), y(y)
{}

Point::Point(const Point& other) :x(other.x), y(other.y)
{}

Point&	Point::operator=(const Point& other)
{
	std::cout << "x and y are const, assignment does nothing\n"
			<< "This operator exists only to satisfy the canonical form" << std::endl;
	(void)other;
	return (*this);
}

Point::~Point()
{}

Fixed	Point::getX() const
{
	return (x);
}

Fixed	Point::getY() const
{
	return (y);
}
