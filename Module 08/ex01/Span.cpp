#include "Span.hpp"
#include <cstdlib>
#include <algorithm>
#include <iostream>

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

unsigned int	Span::size(void) const
{
	return (_size);
}

static int	calc_span(int a, int b)
{
	return (a - b);
}

unsigned int	Span::shortestSpan(void) const
{
	std::vector<int>	temp(_data.begin(), _data.begin() + _filled);
	std::vector<int>	diff(_filled - 1);
	
	if (_filled <= 1)
		throw (TooFewElementsException());
	std::sort(temp.begin(), temp.end());
	std::transform(temp.begin() + 1, temp.end(), temp.begin(), diff.begin(), calc_span);
	return (*std::min_element(diff.begin(), diff.end()));
}

unsigned int	Span::longestSpan(void) const
{
	std::vector<int>	temp(_data.begin(), _data.begin() + _filled);

	if (_filled <= 1)
		throw (TooFewElementsException());
	std::sort(temp.begin(), temp.end());
	return (*(temp.end() - 1) - *temp.begin());
}

const char	*Span::FullException::what(void) const throw()
{
	return ("Span::FullException");
}

const char	*Span::TooFewElementsException::what(void) const throw()
{
	return ("Span::TooFewElementsException");
}
