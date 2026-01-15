#include "Point.hpp"

static Fixed	triangle_area(const Point a, const Point b, const Point c)
{
	Fixed	area;

	area = (a.get_x() * (b.get_y() - c.get_y()));
	area = area + b.get_x() * (c.get_y() - a.get_y());
	area = area + c.get_x() * (a.get_y() - b.get_y());
	if (area < Fixed(0))
		area = area * Fixed(-1);
	area = area / Fixed(2);
	return (area);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	ABC;
	Fixed	PBC;
	Fixed	APC;
	Fixed	ABP;

	ABC = triangle_area(a, b, c);
	if (ABC == Fixed(0))
		return (false);
	PBC = triangle_area(point, b, c);
	APC = triangle_area(a, point, c);
	ABP = triangle_area(a, b, point);
	if (PBC == Fixed(0) || APC == Fixed(0) || ABP == Fixed(0))
		return (false);
	if (ABC != PBC + APC + ABP)
		return (false);
	return (true);
}
