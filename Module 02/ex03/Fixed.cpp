#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int	Fixed::_fractional_bits = 8;

Fixed::Fixed(void)
{
	_value = 0;
	std::cerr << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int ivalue)
{
	_value = ivalue << _fractional_bits;
	std::cerr << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fvalue)
{
	_value = (int)roundf(fvalue * (1 << _fractional_bits));
	std::cerr << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	this->_value = other._value;
	std::cerr << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
		this->_value = other._value;
	std::cerr << "Copy assignment operator called" << std::endl;
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cerr << "Destructor called" << std::endl;
}

int	Fixed::getRawBits(void) const
{
	std::cerr << "getRawBits called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int raw)
{
	std::cerr << "setRawBits called" << std::endl;
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

bool	Fixed::operator>(const Fixed& other) const
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return (this->_value != other._value);
}

Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	sum;

	sum._value = this->_value + other._value;
	return (sum);
}

Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	sum;

	sum._value = this->_value - other._value;
	return (sum);
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	product;

	product._value = (this->_value * other._value) >> _fractional_bits;
	return (product);
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	product;

	product._value = (this->_value << _fractional_bits) / other._value;
	return (product);
}

Fixed&	Fixed::operator++(void)
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	original(*this);

	this->_value++;
	return (original);
}

Fixed&	Fixed::operator--(void)
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	original(*this);
	
	this->_value--;
	return (original);
}

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	return (f2);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}
