#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>

class	ClapTrap
{
	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		ClapTrap&	operator=(const ClapTrap& other);
		virtual ~ClapTrap(void);

		virtual const std::string	getClass(void) const;

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	printStatus(void) const;

	protected:
		ClapTrap(std::string name, int hp, int ep, int attk_dmg);

		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;

		static const int	_init_hit_points;
		static const int	_init_energy_points;
		static const int	_init_attack_damage;
};

#endif
