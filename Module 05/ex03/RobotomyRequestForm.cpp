#include "RobotomyRequestForm.hpp"
#include <fstream>
#include <cstdlib>

const int	RobotomyRequestForm::SIGN_GRADE = 72;
const int	RobotomyRequestForm::EXEC_GRADE = 45;

RobotomyRequestForm::RobotomyRequestForm(void)
	:AForm("RobotomyRequestForm", "", SIGN_GRADE, EXEC_GRADE)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	:AForm("RobotomyRequestForm", target, SIGN_GRADE, EXEC_GRADE)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	:AForm(other)
{
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::_action(void) const
{
	std::cout << "\033[3m=-=-=DRILLING NOISES=-=-=\033[0m\n";
	if (std::rand() % 2)
		std::cout << getTarget() << " has been robotomized 🤖" << std::endl;
	else
		std::cout << getTarget() << "'s robotomy failed!" << std::endl;
}
