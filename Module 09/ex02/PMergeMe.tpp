#include <algorithm>

template<typename T>
PMergeMe<T>::PMergeMe(T& data, int group_size)
	:_data(data),
	 _group_size(group_size),
	 _comparisons(0)
{
}

template<typename T>
PMergeMe<T>::~PMergeMe(void)
{
}

template<typename T>
size_t	PMergeMe<T>::size(void) const
{
	return (_data.size() / _group_size);
}

template<typename T>
void	PMergeMe<T>::sort(T& data)
{
	PMergeMe	sequence(data, 1);

	sequence.mergeInsert();	
}

template<typename T>
void	PMergeMe::mergeInsert(void)
{
	for (size_t i = 0; i < size() / 2; ++i)
	{
		if ((*this)[i * 2] > (*this)[i * 2 + 1])
			
	}
}
