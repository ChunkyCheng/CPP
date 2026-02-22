#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <stdexcept>
# include <iostream>

template<typename T>
int&	easyfind(T& container, const int target)
{
	typename T::iterator	it;

	it = container.begin();
	while (it != container.end())
	{
		if (*it == target)
			return (*it);
		++it;
	}
	throw (std::exception());
}

template<typename T>
std::ostream& print_container(const T& container)
{
	typename T::const_iterator	it;

	it = container.begin();
	while (1)
	{
		std::cout << *it;
		++it;
		if (it == container.end())
			break ;
		std::cout << ", ";
	}
	return (std::cout);
}

#endif
