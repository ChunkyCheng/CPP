#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	ShouXiang("Shou Xiang");
	ScavTrap	Marcus("Marcus");
	ScavTrap	clone;
	ClapTrap	*Maz_ptr;

	Marcus.guardGate();
	Marcus.takeDamage(20);
	clone = ScavTrap(Marcus);
	clone.takeDamage(30);
	Maz_ptr = new ScavTrap("Maz");
	Maz_ptr->takeDamage(90);
	delete Maz_ptr;

	Marcus.ClapAttk("Dummy");
}
