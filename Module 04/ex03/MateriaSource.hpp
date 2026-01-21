#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource& other);
		MateriaSource&	operator=(const MateriaSource& other);
		~MateriaSource(void);

		void		learnMateria(AMateria *m);
		AMateria	*createMateria(const std::string& type);

	protected:
	private:
		static const int	_TEMPLATE_COUNT = 4;
		AMateria			*_templates[_TEMPLATE_COUNT];	
};

#endif
