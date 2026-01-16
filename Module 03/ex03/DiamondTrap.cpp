#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
	:ClapTrap("_clap_name",
			FragTrap::_init_hit_points,
			ScavTrap::_init_energy_points,
			FragTrap::_init_attack_damage)
{
	std::cout << "DiamondTrap default constructor called: "  << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
	:ClapTrap(name + "_clap_name",
			FragTrap::_init_hit_points,
			ScavTrap::_init_energy_points,
			FragTrap::_init_attack_damage),
	 _name(name)
{
	std::cout << "DiamondTrap" << " name constructor called: " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	:ClapTrap(other),
	 _name(other._name)
{
	std::cout << "DiamondTrap" << " copy constructor called: " << _name << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "DiamondTrap copy assignment operator called: " << _name << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called: " << _name << std::endl;
}


const std::string	DiamondTrap::getClass(void) const { return ("DiamondTrap"); }
