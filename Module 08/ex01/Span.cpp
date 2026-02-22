#include "Span.hpp"
#include <cstdlib>

Span::Span(void) {}

Span::Span(unsigned int N)
	:_size(N), _filled(0), _data(N)
{
}

Span::Span(const Span& other)
	:_size(other._size), _filled(other._filled), _data(other._data)
{
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		_size = other._size;
		_filled = other._filled;
		_data = other._data;
	}
	return (*this);
}

Span::~Span(void) {}

void	Span::addNumber(int number)
{
	if (_filled == _size)
		throw (FullException());
	_data[_filled] = number;
	_filled++;
}

unsigned int	Span::shortestSpan(void) const
{
	unsigned int	min;
	unsigned int	distance;

	if (_filled <= 1)
		throw (TooFewElementsException());
	min = std::abs(_data[0] - _data[1]);
	for (unsigned int i = 2; i < _filled; ++i)
	{
		distance = std::abs(_data[i - 1] - _data[i]);
		if (distance < min)
			min = distance;
	}
	return (min);
}

unsigned int	Span::longestSpan(void) const
{
	unsigned int	max;
	unsigned int	distance;
	if (_filled <= 1)
		throw (TooFewElementsException());
	max = 0;
	for (unsigned int i = 1; i < _filled; ++i)
	{
		distance = std::abs(_data[i - 1] - _data[i]);
		if (distance > max)
			max = distance;
	}
	return (max);
}

const char	*Span::FullException::what(void) const throw()
{
	return ("Span::FullException");
}

const char	*Span::TooFewElementsException::what(void) const throw()
{
	return ("Span::TooFewElementsException");
}
