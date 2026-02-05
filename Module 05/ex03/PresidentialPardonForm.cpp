#include "PresidentialPardonForm.hpp"
#include <fstream>

const int	PresidentialPardonForm::SIGN_GRADE = 25;
const int	PresidentialPardonForm::EXEC_GRADE = 5;

PresidentialPardonForm::PresidentialPardonForm(void)
	:AForm("PresidentialPardonForm", "", SIGN_GRADE, EXEC_GRADE)
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	:AForm("PresidentialPardonForm", target, SIGN_GRADE, EXEC_GRADE)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	:AForm(other)
{
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

void	PresidentialPardonForm::_action(void) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox!" << std::endl;
}
