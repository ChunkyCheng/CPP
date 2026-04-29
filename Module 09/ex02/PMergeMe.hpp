#ifndef PMERGEME_HPP
# define PMERGEME_HPP

template<typename T>
class	PMergeMe
{
	private:
		PMergeMe(void);
		PMergeMe(T& data, int group_size);
		PMergeMe(const PMergeMe& other);
		PMergeMe&	operator=(const PMergeMe& other);
		~PMergeMe(void);

	public:
		static void	sort(T& sequence);
	
	private:
		const size_t	_group_size;
		T&				_data;
		int				_comparisons;

		size_t	size(void) const;
		T		operator[](size_t index);
		void	mergeInsert(void);
};

#endif
