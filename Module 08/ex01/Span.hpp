#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class	Span
{
	private:
		Span(void);
	public:
		Span(unsigned int N);
		Span(const Span& other);
		Span&	operator=(const Span& other);
		~Span(void);

		void			addNumber(int number);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

	protected:
	private:
		unsigned int		_size;
		unsigned int		_filled;
		std::vector<int>	_data;

	public:
		class	FullException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class	TooFewElementsException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

#endif
