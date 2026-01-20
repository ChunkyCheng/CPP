#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
	:Animal("Cat"), _brain(NULL)
{
	_brain = new Brain;
	std::cerr << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other)
	:Animal(other), _brain(NULL)
{
	if (other._brain)
		_brain = new Brain(*other._brain);
	std::cerr << "Cat copy constructor called" << std::endl;
}

Cat&	Cat::operator=(const Cat& other)
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
	std::cerr << "Cat copy assignment operator called" << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete _brain;
	std::cerr << "Cat destructor called" << std::endl;
}

const std::string&	Cat::getIdea(unsigned int index) const
{
	return (_brain->getIdea(index));
}

void	Cat::setIdea(unsigned int index, std::string idea) const
{
	return (_brain->setIdea(index, idea));
}

void	Cat::makeSound(void) const
{
	std::cout << "\e[3mMeow\e[0m" << std::endl;
}
