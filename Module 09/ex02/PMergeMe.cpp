#include "PMergeMe.hpp"
#include <iostream>
#include <cmath>

PMergeMe::PMergeMe(void)
{
}

PMergeMe::PMergeMe(const PMergeMe& other)
{
	(void)other;
}

PMergeMe&	PMergeMe::operator=(const PMergeMe& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

PMergeMe::~PMergeMe(void)
{
}

static void	print_groups(std::vector<unsigned int>& nums, int group_size, bool swap)
{
	for (unsigned int i = 0; i < nums.size(); ++i)
	{
		if (swap && i % (group_size * 2) == 0 && i + group_size * 2 <= nums.size())
			std::cout << "\033[1;31m[\033[0m";
		if (i % group_size == 0 && i + group_size <= nums.size())
			std::cout << "[";
		std::cout << nums[i];
		if (static_cast<int>(i) % group_size == group_size - 1)
			std::cout << "]";
		if (swap && static_cast<int>(i) % (group_size * 2) == group_size * 2 - 1)
			std::cout << "\033[1;31m]\033[0m";
		if (i + 1 != nums.size())
			std::cout << ", ";
	}
}

static unsigned int	lastInGroup(std::vector<unsigned int>& nums, int group_size, int i)
{
	return (nums[i * group_size + group_size - 1]);
}

void	swap_groups(std::vector<unsigned int>& nums, int group_size, int i)
{
	for (int j = 0; j < group_size; ++j)
		swap(nums[i * group_size + j], nums[i * group_size + group_size + j]);
}

void	jacobsthal_insert(std::vector<unsigned int>& nums, int group_size)
{
	std::vector<unsigned int>	pend;
	unsigned int				i;
	unsigned int				j;
	unsigned int				loop_limit;

	i = group_size * 2;
	j = i;
	loop_limit = nums.size() / group_size * group_size;
	while (i < loop_limit)
	{
		if ((i / group_size) % 2 == 0)
		{
			pend.push_back(nums[j]);
			nums.erase(nums.begin() + j);
		}
		else
			++j;
		++i;
	}
	std::cout << "pend:\n";
	print_groups(pend, group_size, false);
	std::cout << "\nmain:\n";
	print_groups(nums, group_size, false);
	std::cout << "\n\n";
	for (unsigned int k = 0; k < pend.size(); ++k)
		nums.push_back(pend[k]);

}

void	merge_insert(std::vector<unsigned int>& nums, int group_size)
{
	if (group_size * 2 > static_cast<int>(nums.size()))
	{
		std::cout << "initiating jacobsthal insertion\n";
		return ;
	}
	std::cout << "Before swaps:\n";
	print_groups(nums, group_size, true);
	std::cout << "\n";
	for (unsigned int i = 0; i + 1 < nums.size() / group_size; i += 2)
	{
		if (lastInGroup(nums, group_size, i) > lastInGroup(nums, group_size, i + 1))
			swap_groups(nums, group_size, i);
	}
	std::cout << "After swaps:\n";
	print_groups(nums, group_size, true);
	std::cout << "\n\n";
	merge_insert(nums, group_size * 2);
	jacobsthal_insert(nums, group_size);
}

void	PMergeMe::sort(std::vector<unsigned int>& nums)
{
	merge_insert(nums, 1);
	std::cout << std::endl;
}
