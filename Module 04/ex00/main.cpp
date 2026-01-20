#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
	}

	std::cout << std::endl;
	
	{
		const Animal*		meta = new Animal();
		const Animal* 		j = new Dog();
		const WrongAnimal*	i = new WrongCat();
		const WrongCat*		wack = new WrongCat();	

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		wack->makeSound();
		i->makeSound(); //will output the wronganimal sound!
		j->makeSound();
		meta->makeSound();
		delete meta;
		delete j;
		delete i;
		delete wack;
	}

	return (0);
}
