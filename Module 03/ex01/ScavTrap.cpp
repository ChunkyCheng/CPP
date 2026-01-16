#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
	:ClapTrap("", 100, 50 ,20)
{
	std::cerr << "ScavTrap default constructor called: " << getName() << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	:ClapTrap(name, 100, 50, 20)
{
	std::cerr << "ScavTrap name constructor called: " << getName() << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	:ClapTrap(other)
{
	std::cerr << "ScavTrap copy constructor called: " << getName() << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cerr << "ScavTrap copy assignment operator called: " << getName() << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cerr << "ScavTrap destructor called: " << getName() << std::endl;
}

const std::string	ScavTrap::getClass(void) const { return ("ScavTrap"); }

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << getName() << " is now in gatekeeper mode" << std::endl;
}
