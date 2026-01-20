#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
	:Animal("Dog"), _brain(NULL)
{
	_brain = new Brain;
	std::cerr << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other)
	:Animal(other), _brain(NULL)
{
	if (other._brain)
		_brain = new Brain(*other._brain);
	std::cerr << "Dog copy constructor called" << std::endl;
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
	std::cerr << "Dog copy assignment operator called" << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cerr << "Dog destructor called" << std::endl;
}

const std::string&	Dog::getIdea(unsigned int index) const
{
	return (_brain->getIdea(index));
}

void	Dog::setIdea(unsigned int index, std::string idea) const
{
	return (_brain->setIdea(index, idea));
}

void	Dog::makeSound(void) const
{
	std::cout << "\e[3mWoof Woof\e[0m" << std::endl;
}
