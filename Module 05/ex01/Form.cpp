#include "Form.hpp"

const int	Form::GRADE_HIGHEST = 1;
const int	Form::GRADE_LOWEST = 150;

Form::Form(void)
	:_name(), _signed(false),
	 _grade_to_sign(GRADE_LOWEST),
	 _grade_to_execute(GRADE_LOWEST)
{
	std::cerr << "Form constructed" << std::endl;
}

Form::Form(const std::string& name, int grade_to_sign, int grade_to_execute)
	:_name(name), _signed(false),
	 _grade_to_sign(grade_to_sign),
	 _grade_to_execute(grade_to_execute)
{
	std::cerr << "Form constructed with name " << _name
			  << ", grade to sign " << _grade_to_sign
			  << " and grade to execute " << _grade_to_execute << std::endl;
	_checkGrade();
}

Form::Form(const Form& other)
	:_name(other._name), _signed(other._signed),
	 _grade_to_sign(other._grade_to_sign),
	 _grade_to_execute(other._grade_to_execute)
{
	std::cerr << "Form copy constructed" << std::endl;
}

Form&	Form::operator=(const Form& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_signed = other._signed;
	}
	std::cerr << "Form copy assignment operator called" << std::endl;
	return (*this);
}

Form::~Form(void)
{
	std::cerr << "Form " << _name << " destructed" << std::endl;
}

const std::string&	Form::getName(void) const
{
	return (_name);
}

bool	Form::getSigned(void) const
{
	return (_signed);
}

int	Form::getGradeToSign(void) const
{
	return (_grade_to_sign);
}

int	Form::getGradeToExecute(void) const
{
	return (_grade_to_execute);
}

void	Form::beSigned(const Bureaucrat& signer)
{
	if (_grade_to_sign < signer.getGrade())
		throw (GradeTooLowException());
	_signed = true;

}

void	Form::_checkGrade(void)
{
	if (_grade_to_sign < GRADE_HIGHEST || _grade_to_execute < GRADE_HIGHEST)
		throw (GradeTooHighException());
	if (_grade_to_sign > GRADE_LOWEST || _grade_to_execute > GRADE_LOWEST)
		throw (GradeTooLowException());
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form::GradeTooHighException");
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form::GradeTooLowException");
}
std::ostream&	operator<<(std::ostream& os, const Form& obj)
{
	os	<< "Form " << obj.getName()
		<< ", signed: " << obj.getSigned()
		<< ", Grade to Sign: " << obj.getGradeToSign()
		<< ", Grade to Execute: " << obj.getGradeToExecute();
	return (os);
}
