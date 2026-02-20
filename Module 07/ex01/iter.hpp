#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template<typename T, const size_t N>
void	iter(T (*arr)[N], void (*func)(T&))
{
	for (size_t i = 0; i < N; ++i)
		func((*arr)[i]);
}

template<typename T, const size_t N>
void	iter(T (*arr)[N], T (*func)(const T&))
{
	for (size_t i = 0; i < N; ++i)
		(*arr)[i] = func((*arr)[i]);
}

template<typename T, const size_t N>
std::ostream&	print_array(T (*arr)[N])
{
	for (size_t i = 0; i < N; ++i)
	{
		std::cout << (*arr)[i];
		if (i != N - 1)
			std::cout << ", ";
	}
	return (std::cout);
}

template<typename T>
T	cube(const T& input)
{
	return(input * input * input);
}

#endif
