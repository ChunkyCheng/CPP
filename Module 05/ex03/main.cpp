#include <iostream>
#include <ctime>
#include <cstdlib>

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void separator(const std::string& title)
{
	std::cout << "\n\033[1;34m==== " << title << " ====\033[0m\n";
}

int main(void)
{
	std::srand(std::time(NULL));

	separator("GRADE BOUNDARY TESTS");

	try
	{
		Bureaucrat high("Aadit", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Correctly caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat low("Steve", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Correctly caught: " << e.what() << std::endl;
	}

	separator("BUREAUCRAT PROMOTION / DEMOTION");

	try
	{
		Bureaucrat mid("Senaru", 2);
		std::cout << mid << std::endl;

		mid.incrementGrade();
		std::cout << "After increment: " << mid << std::endl;

		mid.incrementGrade(); // should throw
	}
	catch (std::exception& e)
	{
		std::cout << "Increment caught: " << e.what() << std::endl;
	}

	separator("INTERN CREATION");

	Intern someRandomIntern;

	AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "home");
	AForm* robo = someRandomIntern.makeForm("robotomy request", "George Droyd");
	AForm* pardon = someRandomIntern.makeForm("presidential pardon", "Gabriel");
	AForm* invalid = someRandomIntern.makeForm("coffee request", "me");

	separator("SIGNING AND EXECUTION TESTS");

	Bureaucrat boss("Shanice", 1);
	Bureaucrat worker("Athan", 140);

	if (shrub)
	{
		worker.signForm(*shrub);
		worker.executeForm(*shrub); // should fail execute (grade too low)

		boss.executeForm(*shrub);   // should work
	}

	separator("ROBOTOMY MULTIPLE EXECUTIONS");

	if (robo)
	{
		boss.signForm(*robo);

		for (int i = 0; i < 5; ++i)
			boss.executeForm(*robo);
	}

	separator("PRESIDENTIAL PARDON");

	if (pardon)
	{
		boss.signForm(*pardon);
		boss.executeForm(*pardon);
	}

	separator("EXECUTE UNSIGNED FORM");

	ShrubberyCreationForm unsignedForm("garden");
	try
	{
		boss.executeForm(unsignedForm);
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << std::endl;
		// should not reach here since executeForm handles exceptions
	}

	separator("POLYMORPHIC DELETION");

	delete shrub;
	delete robo;
	delete pardon;
	delete invalid; // safe even if NULL

	separator("DONE");

	return 0;
}
