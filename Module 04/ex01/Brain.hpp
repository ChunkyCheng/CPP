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

	protected:
	private:
		std::string					_ideas[100];
		static const unsigned int	_idea_count;
};

#endif
