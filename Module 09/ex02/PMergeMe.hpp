#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>

class	PMergeMe
{
	public:
		PMergeMe(void);
		PMergeMe(const PMergeMe& other);
		PMergeMe&	operator=(const PMergeMe& other);
		~PMergeMe(void);

	public:
		void	sort(std::vector<unsigned int>& nums);
	
	private:
		struct s_pend
		{
			std::vector<unsigned int>	group;
			unsigned int				bound;
		};
		unsigned int	_comparisons;
};

template<typename T>
void	swap(T& a, T& b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}

#endif
