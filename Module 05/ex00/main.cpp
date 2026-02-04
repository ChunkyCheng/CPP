#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Steve", 120);
		Bureaucrat	b("Aadit", 151);
		std::cout << a << "\n" << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "AHHHHHHHHHH" << std::endl;
	}
	std::cout << ":)" << std::endl;
}
