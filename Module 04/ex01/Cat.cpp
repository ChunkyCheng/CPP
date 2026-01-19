#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
	:Animal("Cat")
{
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	:Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
	std::cout << "Cat copy assignment operator called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "\e[3mMeow\e[0m" << std::endl;
}
