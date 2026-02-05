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
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	a("Steve", 120);
		Bureaucrat	b("Aadit", 2);
		std::cout << a << "\n" << b << std::endl;
		b.incrementGrade();
		std::cout << a << "\n" << b << std::endl;
		b.incrementGrade();
		std::cout << a << "\n" << b << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
