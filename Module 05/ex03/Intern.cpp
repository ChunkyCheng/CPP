#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

const std::string	Intern::_form_names[] = {"shrubbery creation",
											"robotomy request",
											"presidential pardon"};
const int			Intern::_FORM_TYPES = sizeof(Intern::_form_names) / sizeof(std::string);

Intern::Intern(void)
{
}

Intern::Intern(const Intern& other)
{
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	if (this != &other)
	{
	}
	return (*this);
}

Intern::~Intern(void)
{
}

AForm	*Intern::makeForm(const std::string& name, const std::string& target)
{
	int		i;
	AForm	*form;

	i = 0;
	while (i < _FORM_TYPES)
	{
		if (_form_names[i] == name)
			break ;
		++i;
	}
	switch (i)
	{
		case 0:
			form = new ShrubberyCreationForm(target);
			break ;
		case 1:
			form = new RobotomyRequestForm(target);
			break ;
		case 2:
			form = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << name << " is not an existing form type" << std::endl;
			return (NULL);
	}
	std::cout << "Intern creates a(n) " << name << " form" << std::endl;
	return (form);
}
