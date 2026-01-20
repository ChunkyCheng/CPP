#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

class	IMateriaSource
{
	protected:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource& other);
		IMateriaSource&	operator=(const IMateriaSource& other);
		
	public:
		virtual ~IMateriaSource(void);
		virtual void		learnMateria(AMateria *) = 0;
		virtual AMateria	*createMateria(const std::string& type) = 0;

	protected:
	private:
};

#endif
