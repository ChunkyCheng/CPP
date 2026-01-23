#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include <iostream>

int main()
{
	{
		MateriaSource	*iceSrc = new MateriaSource();
		iceSrc->learnMateria(new Ice());
		iceSrc->learnMateria(new Ice());
		iceSrc->learnMateria(new Ice());
		iceSrc->learnMateria(new Ice());
		iceSrc->learnMateria(new Ice());	//source should be full
		MateriaSource	*deepCopy = new MateriaSource(*iceSrc);

		ICharacter	*me = new Character("me");
		me->equip(deepCopy->createMateria("ice"));
		me->equip(deepCopy->createMateria("ice"));
		me->equip(deepCopy->createMateria("ice"));
		me->equip(deepCopy->createMateria("cure"));
		me->equip(deepCopy->createMateria(""));
		me->equip(deepCopy->createMateria("ice"));
		me->equip(deepCopy->createMateria("ice"));
		AMateria	*tmp = me->getEquipment(2);
		me->unequip(2);
		delete tmp;
		me->equip(deepCopy->createMateria("ice"));

		delete iceSrc;
		delete deepCopy;
		delete me;
	}

	std::cout << std::endl;

	IMateriaSource	*src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());


	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");

	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
	return 0;
}
