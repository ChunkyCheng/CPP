#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <ctime>
#include <vector>
#include <deque>
#include <algorithm>
#include "PmergeMe.hpp"

static bool	parse(char*	argv[], std::vector<int>& nums)
{
	char	*endptr;

	for (int i = 1; argv[i]; ++i)
	{
		long num = std::strtol(argv[i], &endptr, 10);
		if (num > INT_MAX || num < 1 || errno == ERANGE || *endptr != '\0')
		{
			std::cerr << "Error: all inputs must be positive integers" << std::endl;
			return (false);
		}
		nums.push_back(static_cast<int>(num));
	}
	return (true);
}

static long long gettime_usec(void)
{
	struct timespec	ts;
	
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((long long)ts.tv_sec * 1000000LL + (long long)ts.tv_nsec / 1000LL);
}

int	main(int argc, char *argv[])
{
	std::vector<int>	nums;

	if (argc == 1)
	{
		std::cerr << "Usage: " << argv[0] << " <integer> [...]" << std::endl;
		return (1);
	}
	if (parse(argv, nums) == false)
		return (2);

	std::vector<int>	vector(nums.begin(), nums.end());
	std::deque<int>		deque(nums.begin(), nums.end());

	std::cout << "Before:\t";
	for (size_t i = 0; i < nums.size(); ++i)
		std::cout << nums[i] << " ";
	std::cout << "\n";
	std::sort(nums.begin(), nums.end());
	std::cout << "After:\t";
	for (size_t i = 0; i < nums.size(); ++i)
		std::cout << nums[i] << " ";
	std::cout << "\n";
	
	long long	start_time;

	start_time = gettime_usec();
	PmergeMe<std::vector<int> >::sort(vector);
	std::cout << "Time to process a range of " << vector.size()
			  << " elements with std::vector : "
			  << gettime_usec() - start_time << "us\n";
	start_time = gettime_usec();
	PmergeMe<std::deque<int> >::sort(deque);
	std::cout << "Time to process a range of " << vector.size()
		  	  << " elements with std::deque  : "
		  	  << gettime_usec() - start_time << "us\n";
	if (std::adjacent_find
		(vector.begin(), vector.end(), std::greater<int>()) != vector.end()
		|| std::adjacent_find
		(deque.begin(), deque.end(), std::greater<int>()) != deque.end())
		std::cout << "\033[1;31mKO\033[0m" << std::endl;
}
