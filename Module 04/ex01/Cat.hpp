#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat : public Animal
{
	public:
		Cat(void);
		Cat(const Cat& other);
		Cat&	operator=(const Cat& other);
		~Cat(void);

		const std::string&	getIdea(unsigned int index) const;
		void				setIdea(unsigned int index, std::string idea) const;

		void	makeSound(void) const;

	protected:
	private:
		Brain	*_brain;
};

#endif
