#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point);

static void	bsp_message(const Point a, const Point b, const Point c, const Point point)
{
	std::cout << "point P" << point;
	if (bsp(a, b, c, point))
		std::cout << " is inside ";
	else
		std::cout << " is not inside ";
	std::cout << "\ntrianlge ABC" << a << "," << b << "," << c << std::endl;
}
		 
int main(void)
{
	bsp_message(Point(0, 8.28f),
				Point(2, 4.72f),
				Point(-4.36f, 5.4f),
				Point(-2.82f, 5.55f));
	return (0);
}
