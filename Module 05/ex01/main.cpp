#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	a("Steve", 120);
		Bureaucrat	b("Aadit", 150);
		Form		f("Fungus", 120, 120);
		std::cout << a << "\n" << b << std::endl;
		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
		a.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
