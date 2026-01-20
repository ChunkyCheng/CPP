#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
	:WrongAnimal("WrongCat")
{
	std::cerr << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
	:WrongAnimal(other)
{
	std::cerr << "WrongCat copy constructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		WrongAnimal::operator=(other);
	}
	std::cerr << "WrongCat copy assignment operator called" << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cerr << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "\e[3mwoeM?\e[0m" << std::endl;
}
