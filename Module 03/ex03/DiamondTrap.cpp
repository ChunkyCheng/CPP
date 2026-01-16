#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
	:ClapTrap()
{
	std::cout << "DiamondTrap default constructor called: "  << std::endl;
}



DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called: " << std::endl;
}


const std::string	DiamondTrap::getClass(void) const { return ("DiamondTrap"); }
