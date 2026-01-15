#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	Fixed 		a;
	const Fixed	b(Fixed(5.05f) * Fixed(2));
	Fixed		c;
	Fixed 		d;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	
	c = b / Fixed(-1.1f);
	d = a * Fixed(3.7f);

	std::cout << "\n";
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	std::cout << "\n";
	std::cout << "max: ";
	std::cout << Fixed::max(Fixed::max(Fixed::max(a, b), c), d) << std::endl;
	std::cout << "min: ";
	std::cout << Fixed::min(Fixed::min(Fixed::min(a, b), c), d) << std::endl;
	return (0);
}
