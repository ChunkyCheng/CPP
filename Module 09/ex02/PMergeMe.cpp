#include "PMergeMe.hpp"
#include <iostream>
#include <algorithm>
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

static unsigned int	lastInGroup(int group_size, int i)
{
	return (i * group_size + group_size - 1);
}

static void	swap_groups(std::vector<unsigned int>& nums, int group_size, int i)
{
	for (int j = 0; j < group_size; ++j)
		swap(nums[i * group_size + j], nums[i * group_size + group_size + j]);
}

static void	seperate_pend(std::vector<unsigned int>& nums, std::vector<s_pend>& pend,
int group_size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	loop_limit;

	i = 2;
	j = i;
	loop_limit = nums.size() / group_size;
	while (i < loop_limit)
	{
		if (i % 2 == 0)
		{
			std::vector<unsigned int>	group;

			for (int k = 0; k < group_size; ++k)
				group.push_back(nums[lastInGroup(group_size, j) - k]);
			pend.push_back((s_pend){group, });
			nums.erase(nums.begin() + j);
		}
		else
			++j;
		++i;
	}
}

static void	insert_from_pend(std::vector<unsigned int>& nums,
std::vector<unsigned int>& pend, int group_size, int insert_count)
{
	int	i
}

static void	update_jacobsthal(int& jacobsthal1, int& jacobsthal2)
{
	int	jacobsthal3;

	jacobsthal3 = jacobsthal2 + 2 * jacobsthal1;
	jacobsthal1 = jacobsthal2;
	jacobsthal2 = jacobsthal3;
}

void	jacobsthal_insert(std::vector<unsigned int>& nums, int group_size)
{
	std::vector<s_pend>	pend;
	int					jacobsthal1;
	int					jacobsthal2;

	jacobsthal1 = 1;
	jacobsthal2 = 3;

	seperate_pend(nums, pend, group_size);	
	std::cout << "pend:\n";
	print_groups(pend, group_size, false);
	std::cout << "\nmain:\n";
	print_groups(nums, group_size, false);
	std::cout << "\n\n";
	while (pend.size())
	{
		insert_from_pend(nums, pend, group_size, jacobsthal2 - jacobsthal1);
		update_jacobsthal(jacobsthal1, jacobsthal2);
	}

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
		if (nums[lastInGroup(group_size, i)] > nums[lastInGroup(group_size, i + 1)])
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
