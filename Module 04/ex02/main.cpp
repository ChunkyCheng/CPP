#include <iostream>
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{	
	{
		
		//Animal	abstract;
		Animal	*abstract_ptr = new Cat();
		delete	abstract_ptr;
		*abstract_ptr = *(new Dog());
	}
	return (0);
}
