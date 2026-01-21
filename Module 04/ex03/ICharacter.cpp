#include "ICharacter.hpp"

ICharacter::ICharacter(void)
{
}

ICharacter::ICharacter(const ICharacter& other)
{
	(void)other;
}

ICharacter&	ICharacter::operator=(const ICharacter& other)
{
	if (this != &other)
	{
	}
	return (*this);
}
