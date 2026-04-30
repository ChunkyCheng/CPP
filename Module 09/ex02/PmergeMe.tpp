#include <algorithm>

template<typename T>
std::ofstream	PmergeMe<T>::_nullstream("/dev/null");

template<typename T>
std::ostream&	PmergeMe<T>::_out
	= PmergeMe<T>::_debug ? std::cerr : PmergeMe<T>::_nullstream;

template<typename T>
PmergeMe<T>::PmergeMe(T& data, int group_size)
	:_group_size(group_size),
	 _data(data),
	 _comparisons(0)
{
}

template<typename T>
PmergeMe<T>::~PmergeMe(void)
{
}

template<typename T>
const T&	PmergeMe<T>::getData(void) const { return (_data); }

template<typename T>
size_t	PmergeMe<T>::getGroupSize(void) const { return (_group_size); }

template<typename T>
size_t	PmergeMe<T>::size(void) const
{
	return (_data.size() / _group_size);
}

template<typename T>
void	PmergeMe<T>::insert(size_t index, s_group val)
{
	s_group	group = (*this)[index];

	_data.insert(group.begin, val.begin, val.end);
}

template<typename T>
void	PmergeMe<T>::erase(size_t index)
{
	s_group	group = (*this)[index];

	_data.erase(group.begin, group.end);
}

template<typename T>
size_t	PmergeMe<T>::find(typename T::value_type val)
{
	typename T::iterator	val_pos = std::find(_data.begin(), _data.end(), val);

	return (std::distance(_data.begin(), val_pos) / _group_size);
}

template<typename T>
int	PmergeMe<T>::grpcmp(s_group a, s_group b)
{
	++_comparisons;
	return (*(a.end - 1) - *(b.end - 1));
}

template<typename T>
typename PmergeMe<T>::s_group	PmergeMe<T>::operator[](size_t index)
{
	s_group	group;

	group.begin = _data.begin() + index * _group_size;
	group.end = group.begin + _group_size;
	return (group);
}

template<typename T>
void	PmergeMe<T>::mergeInsert(void)
{
	if (size() < 2)
		return ;
	_out << "Before:\n" << *this << "\n";
	for (size_t i = 0; i < size() / 2; ++i)
	{
		s_group	a = (*this)[i * 2];
		s_group b = (*this)[i * 2 + 1];

		if (grpcmp(a, b) > 0)
		{
			T	temp(_group_size);
			std::copy(a.begin, a.end, temp.begin());
			std::copy(b.begin, b.end, a.begin);
			std::copy(temp.begin(), temp.end(), b.begin);
		}
	}
	_out << "After:\n" << *this << "\n";

	PmergeMe<T>	sequence(_data, _group_size * 2);

	_out << "\n";
	sequence.mergeInsert();
	_comparisons += sequence._comparisons;
	_out << "\n";
	jacobsthalInsert();
}

template<typename T>
void	PmergeMe<T>::jacobsthalInsert(void)
{
	T					temp;
	PmergeMe<T>			pend(temp, _group_size);
	std::vector<size_t>	partners;

	initPend(pend, partners);
	_out << "main:\n" << *this << "\n";
	_out << "pend:\n" << pend << "\n";

	size_t	jacobsthal1 = 1;
	size_t	jacobsthal2 = 3;
	while (pend.size())
	{
		for (size_t i = jacobsthal2 - jacobsthal1; i > 0; --i)
		{
			if (i > pend.size())
				continue ;
			
			size_t	insert_idx;

			if (i <= partners.size())
			{
				insert_idx = binaryInsert(0, partners[i - 1], pend[i - 1]);
				partners.erase(partners.begin() + i - 1);
			}
			else
				insert_idx = binaryInsert(0, size(), pend[i - 1]);
			
			std::vector<size_t>::iterator	
			higher = std::lower_bound(partners.begin(), partners.end(),	insert_idx);

			while (higher != partners.end())
				(*higher++)++;
			pend.erase(i - 1);
		}

		size_t	jacobsthal3 = jacobsthal2 + jacobsthal1 * 2;
		jacobsthal1 = jacobsthal2;
		jacobsthal2 = jacobsthal3;
	}
	_out << "After Insert:\n" << *this << "\n";
}

template<typename T>
void	PmergeMe<T>::initPend(PmergeMe<T>& pend, std::vector<size_t>& partners)
{
	size_t	i = 2;
	size_t	j = 2;
	size_t	loop_limit = size();

	while (i < loop_limit)
	{
		if (i % 2 == 0)
		{
			s_group	group = (*this)[j];

			pend.insert(pend.size(), group);
			if (i + 1 < loop_limit)
				partners.push_back(j);
			erase(j);
		}
		else
			++j;
		++i;
	}
}

template<typename T>
size_t	PmergeMe<T>::binaryInsert(size_t min, size_t max, s_group pend_element)
{
	while (min < max)
	{
		size_t	mid = (min + max) / 2;

		if (grpcmp(pend_element, (*this)[mid]) < 0)
			max = mid;
		else
			min = mid + 1;
	}
	insert(min, pend_element);
	return (min);
}

template<typename T>
bool	PmergeMe<T>::checkSuccess(size_t maxComps) const
{
	bool	success = true;

	_out << "Total comparisons: " << _comparisons << "\n";
	_out << "Max comparisons: " << maxComps << "\n";
	if (_comparisons <= maxComps)
		_out << "Comparisons within limits! :)" << "\n";
	else
	{
		_out << "Comparisons beyond limits! >:(" << "\n";
		success = false;
	}
	if (std::adjacent_find
		(_data.begin(), _data.end(), std::greater<int>()) == _data.end())
		_out << "Sorted successfully! :)" << std::endl;
	else
	{
		_out << "Failed to sort! >:(" << std::endl;
		success = false;
	}
	if (success)
		_out << "\033[1;32mOK\n\033[0m";
	else
		_out << "\033[1;31mKO\n\033[0m";
	return (success);
}


template<typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj)
{
	const T&	data = obj.getData();
	size_t		group_size = obj.getGroupSize();
	size_t		i = 0;

	while (i < data.size() / group_size * group_size)
	{
		if (i % group_size == 0)
			os << "[";
		os << data[i];
		if ((i + 1) % group_size == 0)
			os << "]";
		if (i + 1 < data.size())
			os << ", ";
		++i;
	}
	os << "\033[31m";
	while (i < data.size())
	{
		os << data[i];
		if (i + 1 < data.size())
			os << ", ";
		++i;
	}
	os << "\033[0m";
	return (os);
}
