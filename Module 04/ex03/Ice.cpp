#include "Ice.hpp"
#include <iostream>

Ice::Ice(void)
	:AMateria("ice")
{
}

Ice::Ice(const Ice& other)
{
	(void)other;
}

Ice&	Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Ice::~Ice(void)
{
}

AMateria	*Ice::clone(void) const { return (new Ice()); }

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
