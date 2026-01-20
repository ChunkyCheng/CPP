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

	protected:
	private:
		std::string	_name;
		AMateria	*_inventory[4];
};

#endif
