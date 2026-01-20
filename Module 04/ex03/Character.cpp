#include "Character.hpp"

Character::Character(void)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(const std::string& name)
	:_name(name)
{
	for (int i = 0; i < 4; ++i)
		inventory[i] = NULL;
}

Character::Character(const Character& other)
	:_name(other._name)
{
	for (int i = 0; i < 4; ++i)
		_inventory[i] = other._inventory[i];
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		_equipCount = other._name;
		for (int i = 0; i < 4; ++i)
			_inventory[i] = other._inventory[i];
	}
	return (*this);
}

Character::~Character(void)
{
}

const std::string	getName(void) const { return (_name); }

void	equip(AMateria *m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (i < 4 && _inventory[i] == NULL)
		i++;
	if (i == 4)
		std::cout << _name << "'s inventory is full" << std::endl;
	else
	{
		_inventory[i] = m;
		std::cout << _name << " equips " << m->getType() << " in slot " << i << std::endl;
	}
}

void	unequip(int idx)
{
	if (_inventory[idx] == NULL)
		std::cout << _name << " doesn't have Materia in slot " << idx << std::endl;
	else
	{
		std::cout << _name << " drops " << _inventory[idx]->getType()
				  << " from slot " << idx << std::endl;
		_inventory[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (_inventory[idx] == NULL)
		std::cout << _name << " doesn't have Materia in slot " << idx << std::endl;
	else
		_inventory[idx]->use(target);
}
