#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
	:_type("meta")
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
	:_type(type)
{
	std::cout << "WrongAnimal(type) constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	:_type(other._type)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

const std::string&	WrongAnimal::getType(void) const { return (_type); }

void	WrongAnimal::makeSound(void) const
{
	std::cout << "\e[3mWrong animal noises\e[0m" << std::endl;
}
