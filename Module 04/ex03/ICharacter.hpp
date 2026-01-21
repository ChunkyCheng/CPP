#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class	AMateria;

class	ICharacter
{
	protected:
		ICharacter(void);
		ICharacter(const ICharacter& other);
		ICharacter&	operator=(const ICharacter& other);

	public:
		virtual ~ICharacter(void) {};
		virtual const std::string&	getName(void) const = 0;
		virtual AMateria			*getEquipment(int idx) const = 0;

		virtual	void	equip(AMateria *m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};

#endif
