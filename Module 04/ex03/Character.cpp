#include "Character.hpp"
#include <iostream>

Character::Character(void)
{
	for (int i = 0; i < _SLOT_COUNT; ++i)
		_inventory[i] = NULL;
}

Character::Character(const std::string& name)
	:_name(name)
{
	for (int i = 0; i < _SLOT_COUNT; ++i)
		_inventory[i] = NULL;
}

Character::Character(const Character& other)
	:_name(other._name)
{
	for (int i = 0; i < _SLOT_COUNT; ++i)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character&	Character::operator=(const Character& other)
{
	if (this != &other)
	{
		_name = other._name;
		for (int i = 0; i < _SLOT_COUNT; ++i)
		{
			delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < _SLOT_COUNT; ++i)
		delete _inventory[i];
}

const std::string&	Character::getName(void) const { return (_name); }

AMateria	*Character::getEquipment(int idx) const
{
	if (idx >= _SLOT_COUNT || idx < 0)
		return (NULL);
	return (_inventory[idx]);
}

void	Character::equip(AMateria *m)
{
	int	i;

	if (!m)
		return ;
	i = 0;
	while (i < _SLOT_COUNT && _inventory[i])
		i++;
	if (i == _SLOT_COUNT)
	{
		delete m;
		std::cout << _name << "'s inventory is full" << std::endl;
	}
	else
	{
		_inventory[i] = m;
		std::cout << _name << " equips " << m->getType() << " in slot " << i << std::endl;
	}
}

void	Character::unequip(int idx)
{
	if (idx >= _SLOT_COUNT || idx < 0)
	{
		std::cout << _name << "_name only has " << _SLOT_COUNT << " slots" << std::endl;
		return ;
	}
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
	if (idx >= _SLOT_COUNT || idx < 0)
	{
		std::cout << _name << "name only has " << _SLOT_COUNT << "slots" << std::endl;
		return ;
	}
	if (_inventory[idx] == NULL)
		std::cout << _name << " doesn't have Materia in slot " << idx << std::endl;
	else
		_inventory[idx]->use(target);
}
