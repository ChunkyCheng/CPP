#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
	:Animal("Dog"), _brain(NULL)
{
	_brain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	:Animal(other), _brain(NULL)
{
	if (other._brain)
		_brain = new Brain(*other._brain);
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog&	Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete _brain;
		if (other._brain)
			_brain = new Brain(*other._brain);
		else
			_brain = NULL;
	}
	std::cout << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "\e[3mWoof Woof\e[0m" << std::endl;
}
