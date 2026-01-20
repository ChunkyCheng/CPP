#include "Ice.hpp"

Ice::Ice(void)
	:Amateria("ice")
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

AMateria	*clone(void) const
{
	return (new Ice());
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
