#include "Brain.hpp"
#include <iostream>

Brain::Brain(void)
{
	std::cerr << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
	unsigned int	i;

	i = 0;
	while (i < _IDEA_COUNT)
	{
		this->_ideas[i] = other._ideas[i];
		++i;
	}
	std::cerr << "Brain copy constructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& other)
{
	unsigned int	i;

	if (this != &other)
	{
		i = 0;
		while (i < _IDEA_COUNT)
		{
			this->_ideas[i] = other._ideas[i];
			++i;
		}
	}
	std::cerr << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain(void)
{
	std::cerr << "Brain destructor called" << std::endl;
}

const std::string&	Brain::getIdea(unsigned int index) const
{
	return (_ideas[index % _IDEA_COUNT]);
}

void	Brain::setIdea(unsigned int index, std::string idea)
{
	if (index >= _IDEA_COUNT)
		return ;
	_ideas[index] = idea;
}
