#include <stdexcept>

template<typename T>
Array<T>::Array(void)
	:_size(0)
{
	_data = new T[0];
}

template<typename T>
Array<T>::Array(unsigned int n)
	:_size(n)
{
	_data = new T[n];
}

template<typename T>
Array<T>::Array(const Array& other)
	:_size(other._size)
{
	_data = new T[other._size];
	for (unsigned int i = 0; i < other._size; ++i)
		_data[i] = other._data[i];
}

template<typename T>
Array<T>&	Array<T>::operator=(const Array& other)
{
	_size = other._size;
	delete[] _data;
	if (this != &other)
	{
		_data = new T[other._size];
		for (unsigned int i = 0; i < other._size; ++i)
			_data[i] = other._data[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array(void)
{
	delete[] _data;
}

template<typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (std::exception());
	return (_data[index]);
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (_size);
}
