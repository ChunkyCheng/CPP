#include "Brain.hpp"
#include <iostream>

const unsigned int Brain::_idea_count = sizeof(Brain::_ideas) / sizeof(Brain::_ideas[0]);

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	unsigned int	i;

	i = 0;
	while (i < _idea_count)
	{
		this->_ideas[i] = other._ideas[i];
		++i;
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	unsigned int	i;

	if (this != &other)
	{
		i = 0;
		while (i < _idea_count)
		{
			this->_ideas[i] = other._ideas[i];
			++i;
		}
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
}
