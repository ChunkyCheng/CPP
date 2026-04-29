#include <algorithm>

template<typename T>
Group<T>::Group(T::iterator begin, T::iterator end)
	:_begin(begin), _end(end)
{
}

template<typename T>
Group&	Group<T>::operator=(const Group& other)
{
	if (this != &other)
		std::copy(_begin, _end, other._begin, other._end);
	return (*this);
}

template<typename T>
Group<T>::~Group(void)
{
}

template<typename T>
Group<T>::operator<(const Group& other)
{
	return (*(_end - 1) < *(other._end - 1));
}
