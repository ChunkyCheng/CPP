#include "AForm.hpp"

const int	AForm::GRADE_HIGHEST = 1;
const int	AForm::GRADE_LOWEST = 150;

AForm::AForm(void)
	:_name(),
	 _target(),
	 _signed(false),
	 _grade_to_sign(GRADE_LOWEST),
	 _grade_to_execute(GRADE_LOWEST)
{
	std::cerr << "AForm constructed" << std::endl;
}

AForm::AForm(const std::string& name, const std::string& target,
			 int grade_to_sign, int grade_to_execute)
	:_name(name),
	 _target(target),
	 _signed(false),
	 _grade_to_sign(grade_to_sign),
	 _grade_to_execute(grade_to_execute)
{
	std::cerr << "AForm constructed with name " << _name
			  << ", target " << _target
			  << ", grade to sign " << _grade_to_sign
			  << " and grade to execute " << _grade_to_execute << std::endl;
	_checkGrade();
}

AForm::AForm(const AForm& other)
	:_name(other._name),
	 _target(other._target),
	 _signed(other._signed),
	 _grade_to_sign(other._grade_to_sign),
	 _grade_to_execute(other._grade_to_execute)
{
	std::cerr << "AForm copy constructed" << std::endl;
}

AForm&	AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_signed = other._signed;
	}
	return (*this);
	std::cerr << "AForm copy assignment operator called" << std::endl;
}

AForm::~AForm(void)
{
	std::cerr << "AForm " << _name << " destructed" << std::endl;
}

const std::string&	AForm::getName(void) const
{
	return (_name);
}

const std::string&	AForm::getTarget(void) const
{
	return (_target);
}

bool	AForm::getSigned(void) const
{
	return (_signed);
}

int	AForm::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int	AForm::getGradeToExecute(void) const
{
	return (_grade_to_execute);
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	if (_grade_to_sign < signer.getGrade())
		throw (GradeTooLowException());
	_signed = true;

}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!_signed)
		throw (NotSignedException());
	if (_grade_to_execute < executor.getGrade())
		throw (GradeTooLowException());
	_action();
}

void	AForm::_action(void) const
{
}

void	AForm::_checkGrade(void)
{
	if (_grade_to_sign < GRADE_HIGHEST || _grade_to_execute < GRADE_HIGHEST)
		throw (GradeTooHighException());
	if (_grade_to_sign > GRADE_LOWEST || _grade_to_execute > GRADE_LOWEST)
		throw (GradeTooLowException());
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm::GradeTooHighException");
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm::GradeTooLowException");
}

const char	*AForm::NotSignedException::what(void) const throw()
{
	return ("AForm::NotSignedException");
}

std::ostream&	operator<<(std::ostream& os, const AForm& obj)
{
	os	<< "AForm " << obj.getName()
		<< ", signed: " << obj.getSigned()
		<< ", Grade to Sign: " << obj.getGradeToSign()
		<< ", Grade to Execute: " << obj.getGradeToExecute();
	return (os);
}
