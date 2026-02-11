#include "C.hpp"

C::C(void)
{
}

C::C(const C& other)
{
	(void)other;
}

C&	C::operator=(const C& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

C::~C(void)
{
}
