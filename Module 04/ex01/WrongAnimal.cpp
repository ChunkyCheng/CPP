#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
	:_type("meta")
{
	std::cerr << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
	:_type(type)
{
	std::cerr << "WrongAnimal(type) constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
	:_type(other._type)
{
	std::cerr << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cerr << "WrongAnimal copy assignment operator called" << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cerr << "WrongAnimal destructor called" << std::endl;
}

const std::string&	WrongAnimal::getType(void) const { return (_type); }

void	WrongAnimal::makeSound(void) const
{
	std::cout << "\e[3mWrong animal noises\e[0m" << std::endl;
}
