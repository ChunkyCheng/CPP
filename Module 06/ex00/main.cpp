#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Usage " << argv[0] << " <input string>" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}
