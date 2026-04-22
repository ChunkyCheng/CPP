#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <pair>

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
