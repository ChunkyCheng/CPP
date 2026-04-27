#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <vector>
#include <algorithm>
#include "PMergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::vector<unsigned int>	sequence;
	char						*endptr;

	if (argc == 1)
	{
		std::cerr << "Usage: " << argv[0] << " <integer> [...]" << std::endl;
		return (1);
	}
	for (int i = 1; argv[i]; ++i)
	{
		long num = std::strtol(argv[i], &endptr, 10);
		if (num > INT_MAX || errno == ERANGE || *endptr != '\0')
		{
			std::cerr << "Error: all inputs must be positive integers" << std::endl;
			return (2);
		}
		if (std::find(sequence.begin(), sequence.end(), num) != sequence.end())
		{
			std::cerr << "Error: duplicate input" << std::endl;
			return (3);
		}
		sequence.push_back(static_cast<int>(num));
	}

	PMergeMe	FordJohnson;

	FordJohnson.sort(sequence);
}
