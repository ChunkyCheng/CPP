#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	ClapTrap	Tristan;
	ClapTrap	Chiang = ClapTrap(Tristan);
	ClapTrap	Melvin = ClapTrap("Melvin");

	Tristan = ClapTrap("Tristan");
	Chiang = ClapTrap("Chiang");

	std::cerr << std::endl;

	ScavTrap	ShouXiang;
	ScavTrap	Marcus("Marcus");
	ScavTrap	Maz = ScavTrap("Maz");

	ShouXiang = ScavTrap("Shou Xiang");

	std::cerr << std::endl;

	FragTrap	Selene;
	FragTrap	Harith(FragTrap("Harith"));
	FragTrap	KeeWan = FragTrap("Kee Wan");

	Selene = FragTrap("Selene");

	std::cerr << std::endl;

	DiamondTrap	Caryn;

	Tristan.printStatus();
	Chiang.printStatus();
	Melvin.printStatus();
	ShouXiang.printStatus();
	Marcus.printStatus();
	Maz.printStatus();
	Selene.printStatus();
	Harith.printStatus();
	KeeWan.printStatus();

	Marcus.attack("Selene");
	Selene.takeDamage(20);
	ShouXiang.guardGate();
	KeeWan.highFivesGuys();

	Marcus.printStatus();
	Selene.printStatus();

	std::cerr << std::endl;
	return (0);
}
