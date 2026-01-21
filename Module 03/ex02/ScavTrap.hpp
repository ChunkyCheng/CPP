#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		ScavTrap&	operator=(const ScavTrap& other);
		~ScavTrap(void);

		const std::string	getClass(void) const;

		void	attack(const std::string &target);
		void	guardGate(void) const;

	protected:
		static const int	_init_hit_points;
		static const int	_init_energy_points;
		static const int	_init_attack_damage;

	private:
};

#endif
