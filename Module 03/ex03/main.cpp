#include <iostream>
#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	Love("Caryn");
	DiamondTrap	Caryn;

	Caryn = Love;

	Love.printStatus();
	Caryn.printStatus();

	Caryn.guardGate();
	Caryn.highFivesGuys();
	Caryn.whoAmI();
	Caryn.attack("Dummy");

	Love.printStatus();
	Caryn.printStatus();
}
