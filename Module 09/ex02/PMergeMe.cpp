#include "PMergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <cmath>
#include "Node.hpp"

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

void	PMergeMe::mergeInsert(std::vector<Node*>& nums)
{

}

void	PMergeMe::sort(std::vector<unsigned int>& nums)
{
	std::vector<Node*>	nodes;

	while (nums.size())
	{
		nodes.push_back(new Node(nums[0]));
		nums.erase(0);
	}
	mergeInsert(nodes);
}
