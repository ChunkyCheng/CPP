#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	public:
		Character(void);
		Character(const std::string& name);
		Character(const Character& other);
		Character&	operator=(const Character& other);
		~Character(void);

		const std::string&	getName(void) const;
		AMateria			*getEquipment(int idx) const;

		void	equip(AMateria *m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

	protected:
	private:
		static const int	_SLOT_COUNT = 4;

		std::string			_name;
		AMateria			*_inventory[_SLOT_COUNT];
};

#endif
