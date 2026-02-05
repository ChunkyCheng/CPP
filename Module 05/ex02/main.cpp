#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	std::srand(std::time(NULL));
	try
	{
		Bureaucrat				a("Steve", 50);
		Bureaucrat				b("Aadit", 145);
		ShrubberyCreationForm	trees("garden");
		ShrubberyCreationForm	plants("mall");
		RobotomyRequestForm		clank("Shanice");
		PresidentialPardonForm	pardon("Senaru");
		b.executeForm(trees);
		b.signForm(trees);
		b.executeForm(trees);
		a.executeForm(trees);
		a.signForm(clank);
		a.signForm(pardon);
		for (int i = 0; i < 140; ++i)
			b.incrementGrade();
		std::cout << a << std::endl;
		b.executeForm(clank);
		b.executeForm(pardon);
		b.signForm(pardon);
		b.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
