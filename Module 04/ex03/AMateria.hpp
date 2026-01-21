#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include "ICharacter.hpp"

class	ICharacter;

class	AMateria
{
	protected:
		AMateria(void);
		AMateria(const std::string& type);
		AMateria(const AMateria& other);
		AMateria&	operator=(const AMateria& other);

	public:
		virtual ~AMateria(void);

		const std::string&	getType(void) const;

		virtual AMateria	*clone(void) const = 0;
		virtual void		use(ICharacter& target);

	protected:
		std::string	_type;

	private:
};

#endif
