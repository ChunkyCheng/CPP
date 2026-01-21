#include "AMateria.hpp"

AMateria::AMateria(void)
{
}

AMateria::AMateria(const std::string& type)
	:_type(type)
{
}

AMateria::AMateria(const AMateria& other)
{
	(void)other;
}

AMateria&	AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

AMateria::~AMateria(void)
{
}

const std::string&	AMateria::getType(void) const { return (_type); }
void				AMateria::use(ICharacter& target) { (void)target; }
