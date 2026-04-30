#include "PmergeMe.hpp"
#include <cmath>
#include <vector>
#include <deque>
#include <list>

static size_t	getMaxComps(size_t size)
{
	ssize_t	sum;

	sum = 0;
	for (size_t k = 1; k <= size; ++k)
	{
		double val = log2(3.0 / 4.0 * static_cast<double>(k));
		sum += static_cast<size_t>(ceil(val));
	}
	return (static_cast<size_t>(sum));
}

template<>
void	PmergeMe<std::vector<int> >::sort(std::vector<int>& nums)
{
	PmergeMe<std::vector<int> >	sequence(nums, 1);

	if (_debug)
		std::cout << "\n\n";
	sequence.mergeInsert();
	if (_debug)
		sequence.checkSuccess(getMaxComps(nums.size()));
}

template<>
void	PmergeMe<std::deque<int> >::sort(std::deque<int>& nums)
{
	PmergeMe<std::deque<int> >	sequence(nums, 1);

	if (_debug)
		std::cout << "\n\n";
	sequence.mergeInsert();
	if (_debug)
		sequence.checkSuccess(getMaxComps(nums.size()));
}
