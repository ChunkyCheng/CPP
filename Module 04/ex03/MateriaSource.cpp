#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < _TEMPLATE_COUNT; ++i)
		_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < _TEMPLATE_COUNT; ++i)
	{
		if (other._templates[i])
			_templates[i] = other._templates[i]->clone();
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < _TEMPLATE_COUNT; ++i)
		{
			delete _templates[i];
			if (other._templates[i])
				_templates[i] = other._templates[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < _TEMPLATE_COUNT; ++i)
		delete _templates[i];
}

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i;

	i = 0;
	while (i < _TEMPLATE_COUNT && _templates[i])
		++i;
	if (i == _TEMPLATE_COUNT)
	{
		delete m;
		std::cout << "Materia Source is full" << std::endl;
	}
	else
		_templates[i] = m;
}

AMateria	*MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i <_TEMPLATE_COUNT; ++i)
	{
		if (_templates[i] && _templates[i]->getType() == type)
			return (_templates[i]->clone());
	}
	std::cout << "Materia Source does not contain any " << type << std::endl;
	return (NULL);
}
