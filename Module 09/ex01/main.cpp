#include "RPN.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	int	result;

	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <RPN Expression>" << std::endl;
		return (1);
	}
	if (RPN::calculateRPN(argv[1], result) == true)
		std::cout << result << std::endl;
	else
		return (2);
}

