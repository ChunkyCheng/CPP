#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class	Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array& other);
		Array&	operator=(const Array& other);
		~Array(void);

	T&				operator[](unsigned int index);
	unsigned int	size(void) const;

	protected:
	private:
		T				*_data;
		unsigned int	_size;
};

#include "Array.tpp"

#endif
