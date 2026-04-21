#include <iostream>
#include <cstdlib>
#include <climits>
#include <cerrno>
#include <vector>
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
		sequence.push_back(std::strtol(argv[i], &endptr, 10));
		if (sequence.back() > INT_MAX || errno == ERANGE || *endptr != '\0')
		{
			std::cerr << "Error: all inputs must be positive integers" << std::endl;
			return (2);
		}
	}

	PMergeMe	FordJohnson;

	FordJohnson.sort(sequence);
}
