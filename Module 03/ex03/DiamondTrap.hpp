#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& other);
		DiamondTrap&	operator=(const DiamondTrap& other);
		~DiamondTrap(void);

		const std::string	getClass(void) const;

		using	ClapTrap::attack;
		void	whoAmI(void) const;

	protected:
		static const int	_init_hit_points;
		static const int	_init_energy_points;
		static const int	_init_attack_damage;

	private:
		std::string	_name;
};

#endif
