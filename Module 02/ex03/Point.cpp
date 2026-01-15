#include "Point.hpp"

Point::Point(void)
	:_x(Fixed(0)), _y(Fixed(0)) {}

Point::Point(const Fixed x, const Fixed y)
	:_x(x), _y(y) {}

Point::Point(const Point& other)
	:_x(other._x), _y(other._y) {}

Point&	Point::operator=(const Point& other)
{
	(void)other;
	std::cerr	<< "Warning: Point class is non-mutable and cannot be reassigned"
				<< std::endl;
	return (*this);
}

Point::~Point(void)
{
}

Fixed	Point::get_x(void) const { return (_x); }

Fixed	Point::get_y(void) const { return (_y); }

std::ostream&	operator<<(std::ostream& os, const Point& obj)
{
	os << "(" << obj.get_x() << ", " << obj.get_y() << ")";
	return (os);
}
