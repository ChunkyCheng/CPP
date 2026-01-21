#include "Cure.hpp"
#include <iostream>

Cure::Cure(void)
	:AMateria("cure")
{
}

Cure::Cure(const Cure& other)
{
	(void)other;
}

Cure&	Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Cure::~Cure(void)
{
}

AMateria	*Cure::clone(void) const { return (new Cure()); }

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
