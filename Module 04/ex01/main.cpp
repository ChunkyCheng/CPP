#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	//proof of deep copy
	{
		Cat	whiskers;
		Cat	mowmow;
		Dog	yummers;
		Dog	princess;

		whiskers.setIdea(10, "kill kill kill kill");
		mowmow.setIdea(20, "I will forget this");
		yummers.setIdea(30, "Jumping is fun");
		princess.setIdea(30, "I'm in heaven!");
		mowmow = whiskers;
		yummers = princess;
		std::cout << "\"" << mowmow.getIdea(10) << "\"" << std::endl;
		std::cout << "\"" << mowmow.getIdea(20) << "\"" << std::endl;
		std::cout << "\"" << yummers.getIdea(30) << "\"" << std::endl;	
	}
	std::cout << std::endl;
	{
		const unsigned int	animal_count = 6;
		Animal				*zoo[animal_count];
		unsigned int		i;

		i = 0;
		while (i < animal_count / 2)
			zoo[i++] = new Dog();
		while (i < animal_count)
			zoo[i++] = new Cat();
		
		i = 0;
		while (i < animal_count)
			delete zoo[i++];
	}

	return (0);
}
