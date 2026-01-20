#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Dog : public Animal
{
	public:
		Dog(void);
		Dog(const Dog& other);
		Dog&	operator=(const Dog& other);
		~Dog(void);

		const std::string&	getIdea(unsigned int index) const;
		void				setIdea(unsigned int index, std::string idea) const;

		void	makeSound(void) const;

	protected:
	private:
		Brain	*_brain;
};

#endif
