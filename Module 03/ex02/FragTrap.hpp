#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : virtual public ClapTrap
{
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(const FragTrap& other);
		FragTrap&	operator=(const FragTrap& other);
		~FragTrap(void);

		const std::string	getClass(void) const;

		void	attack(const std::string& target);
		void	highFivesGuys(void);

	protected:
		static const int	_init_hit_points;
		static const int	_init_energy_points;
		static const int	_init_attack_damage;

	private:
};

#endif
