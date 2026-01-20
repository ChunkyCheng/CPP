#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class	Animal
{
	public:
		virtual ~Animal(void);

		const std::string&	getType(void) const;

		virtual void	makeSound(void) const;

	protected:
		Animal(void);
		Animal(const Animal& other);
		Animal&	operator=(const Animal& other);

		Animal(std::string type);

		std::string	_type;

	private:
};

#endif
