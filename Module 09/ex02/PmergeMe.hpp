#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <cstddef>
#include <iostream>
#include <fstream>
#include <vector>

template<typename T>
class	PmergeMe
{
	private:
		PmergeMe(void);
		PmergeMe(T& data, int group_size);
		PmergeMe(const PmergeMe& other);
		PmergeMe&	operator=(const PmergeMe& other);
		~PmergeMe(void);

	public:
		static void	sort(T& nums);

		const T&		getData(void) const;
		size_t			getGroupSize(void) const;
	
	private:
		typedef std::vector<size_t>	indxvect;
		struct s_group
		{
			typename T::iterator	begin;
			typename T::iterator	end;
		};

		const size_t	_group_size;
		T&				_data;
		size_t			_comparisons;

		size_t			size(void) const;
		void			insert(size_t index, s_group group);
		void			erase(size_t index);
		int				grpcmp(s_group a, s_group b);
		s_group			operator[](size_t index);

		void			mergeInsert(void);
		void			jacobsthalInsert(void);
		void			initPend(PmergeMe<T>& pend, indxvect& partners);
		void			binaryInsert(PmergeMe<T>& pend, indxvect& partners, size_t i);

		static const bool		_debug = false;
		static std::ofstream	_nullstream;
		static std::ostream&	_out;
		bool					checkSuccess(size_t maxComps) const;
};

template<typename T>
std::ostream&	operator<<(std::ostream& os, const PmergeMe<T>& obj);

# include "PmergeMe.tpp"

#endif
