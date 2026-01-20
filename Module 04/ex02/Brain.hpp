#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class	Brain
{
	public:
		Brain(void);
		Brain(const Brain& other);
		Brain&	operator=(const Brain& other);
		~Brain(void);

		const std::string&	getIdea(unsigned int index) const;
		void				setIdea(unsigned int index, std::string idea);

	protected:
	private:
		static const unsigned int	_IDEA_COUNT = 100;
		std::string					_ideas[_IDEA_COUNT];
};

#endif
