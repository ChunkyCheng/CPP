#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
	:_type("meta")
{
	std::cerr << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type)
	:_type(type)
{
	std::cerr << "Animal(type) constructor called" << std::endl;
}

Animal::Animal(const Animal& other)
	:_type(other._type)
{
	std::cerr << "Animal copy constructor called" << std::endl;
}

Animal&	Animal::operator=(const Animal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cerr << "Animal copy assignment operator called" << std::endl;
	return (*this);
}

Animal::~Animal(void)
{
	std::cerr << "Animal destructor called" << std::endl;
}

const std::string&	Animal::getType(void) const { return (_type); }

void	Animal::makeSound(void) const
{
	std::cout << "\e[3mAnimal noises\e[0m" << std::endl;
}
