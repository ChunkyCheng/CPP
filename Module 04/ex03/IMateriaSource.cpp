#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource(void)
{
}

IMateriaSource::IMateriaSource(const IMateriaSource& other)
{
	(void)other;
}

IMateriaSource&	IMateriaSource::operator=(const IMateriaSource& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

IMateriaSource::~IMateriaSource(void)
{
}
