#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
	:_hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cerr << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
	:_name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cerr << "CLapTrap name constructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hp, int ep, int attk_dmg)
	:_name(name), _hit_points(hp), _energy_points(ep), _attack_damage(attk_dmg)
{
	std::cerr << "ClapTrap attribute constructor called: " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	:_name(other._name), _hit_points(other._hit_points),
	 _energy_points(other._energy_points), _attack_damage(other._attack_damage)
{
	std::cerr << "ClapTrap copy constructor called: " << _name << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	std::cerr << "ClapTrap copy assignment operator called: " << _name << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	std::cerr << "ClapTrap destructor called: " << _name << std::endl;
}

const std::string&	ClapTrap::getName(void) const { return (_name); }
const std::string	ClapTrap::getClass(void) const { return ("ClapTrap"); }

void	ClapTrap::attack(const std::string& target)
{
	std::cout << getClass() << " " << _name;
	if (_hit_points <= 0)
		std::cout	<< " could not attack because it is dead" << std::endl;
	else if (_energy_points <= 0)
		std::cout	<< " could not attack because it has no energy" << std::endl;
	else
	{
		std::cout	<< " attacks " << target << ", causing " << _attack_damage
					<< " points of damage!" << std::endl;
		_energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << getClass() << " " << _name;
	if (_hit_points <= 0)
		std::cout << "'s corpse";
	else if (_hit_points <= (int)amount)
		std::cout << " is killed as it";
	_hit_points -= amount;
	std::cout << " takes " << amount << " damage and now has "
			  << _hit_points << " health" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << getClass() << " " << _name;
	if (_energy_points < (int)amount)
	{
		std::cout << " could not repair because it didn't have enough energy"
				  << std::endl;
	}
	else
	{
		_energy_points -= amount;
		_hit_points += amount;
		std::cout << " used " << amount << " energy to repair and now has "
				  << _hit_points << " health" << std::endl;
	}
}
