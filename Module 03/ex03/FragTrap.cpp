#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void)
	:ClapTrap("", 100, 100, 30)
{
	std::cerr << "FragTrap default constructor called: " << getName() << std::endl;
}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name, 100, 100, 30)
{
	std::cerr << "FragTrap name constructor called: " << getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	:ClapTrap(other)
{
	std::cerr << "FragTrap copy constructor called: " << getName() << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cerr << "FragTrap copy assignment operator called: " << getName() << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cerr << "FragTrap destructor called: " << getName() << std::endl;
}

const std::string	FragTrap::getClass(void) const { return ("FragTrap"); }

void	FragTrap::highFivesGuys(void)
{
	std::cout << getClass() << " " << getName()
			  << " requests: \"High fives guys!\"" << std::endl;
}
