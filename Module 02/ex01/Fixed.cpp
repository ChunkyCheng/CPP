#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed(void)
{
	_value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int ivalue)
{
	_value = ivalue << _fractional_bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fvalue)
{
	_value = (int)roundf(fvalue * (1 << _fractional_bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other._value;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int raw)
{
	std::cout << "setRawBits called" << std::endl;
	_value = raw;
}

int	Fixed::toInt(void) const
{
	return (_value >> _fractional_bits);
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fractional_bits));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
