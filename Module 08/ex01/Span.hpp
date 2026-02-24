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
		template<typename T> Span(T begin, T end);
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

template<typename T>
Span::Span(T begin, T end)
{
	_size = 0;
	while (begin != end)
	{
		_data.push_back(*begin);
		_size++;
		begin++;
	}
	_filled = _size;
}

#endif
