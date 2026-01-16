#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	Tristan("Tristan");
	ClapTrap	Tristan_clone;
	ClapTrap	Tristan_clone2(Tristan);
	ClapTrap	Chiang("Chiang");
	ClapTrap	Melvin;

	Tristan_clone = Tristan;
	Melvin = ClapTrap("Melvin");
	Tristan.attack("Chiang");
	Chiang.takeDamage(0);
	Melvin.beRepaired(100);
	Melvin.takeDamage(9);
	Chiang.attack("Tristan");
	Tristan.takeDamage(0);
	Melvin.beRepaired(10);
	Melvin.attack("Chiang");
	Melvin.takeDamage(1);
	Melvin.takeDamage(10);
	Melvin.attack("Tristan");
}
