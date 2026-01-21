#include "ScavTrap.hpp"
#include <iostream>

const int	ScavTrap::_init_hit_points = 100;
const int	ScavTrap::_init_energy_points = 50;
const int	ScavTrap::_init_attack_damage = 20;

ScavTrap::ScavTrap(void)
	:ClapTrap("", 100, 50 ,20)
{
	std::cerr << "ScavTrap default constructor called: " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string name)
	:ClapTrap(name, 100, 50, 20)
{
	std::cerr << "ScavTrap name constructor called: " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other)
	:ClapTrap(other)
{
	std::cerr << "ScavTrap copy constructor called: " << _name << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cerr << "ScavTrap copy assignment operator called: " << _name << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	std::cerr << "ScavTrap destructor called: " << _name << std::endl;
}

const std::string	ScavTrap::getClass(void) const { return ("ScavTrap"); }

void	ScavTrap::attack(const std::string& target)
{
	std::cout << getClass() << " " << _name;
	if (_hit_points <= 0)
		std::cout	<< " could not attack because it is dead" << std::endl;
	else if (_energy_points <= 0)
		std::cout	<< " could not attack because it has no energy" << std::endl;
	else
	{
		std::cout	<< " hits " << target << " with a club, causing " << _attack_damage
					<< " points of damage!" << std::endl;
		_energy_points--;
	}
}

void	ScavTrap::guardGate(void) const
{
	std::cout << getClass() << " " << _name
			  << " is now in gatekeeper mode" << std::endl;
}
