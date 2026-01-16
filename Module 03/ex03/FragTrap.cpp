#include "FragTrap.hpp"
#include <iostream>

const int	FragTrap::_init_hit_points = 100;
const int	FragTrap::_init_energy_points = 100;
const int	FragTrap::_init_attack_damage = 30;

FragTrap::FragTrap(void)
	:ClapTrap("", 100, 100, 30)
{
	std::cerr << "FragTrap default constructor called: " << _name << std::endl;
}

FragTrap::FragTrap(std::string name)
	:ClapTrap(name, 100, 100, 30)
{
	std::cerr << "FragTrap name constructor called: " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
	:ClapTrap(other)
{
	std::cerr << "FragTrap copy constructor called: " << _name << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	std::cerr << "FragTrap copy assignment operator called: " << _name << std::endl;
	return (*this);
}

FragTrap::~FragTrap(void)
{
	std::cerr << getClass() << " destructor called: " << _name << std::endl;
}

const std::string	FragTrap::getClass(void) const { return ("FragTrap"); }

void	FragTrap::highFivesGuys(void)
{
	std::cout << getClass() << " " << _name
			  << " requests: \"High fives guys!\"" << std::endl;
}
