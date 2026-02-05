#include "Bureaucrat.hpp"

const int	Bureaucrat::GRADE_HIGHEST = 1;
const int	Bureaucrat::GRADE_LOWEST = 150;

Bureaucrat::Bureaucrat(void)
	:_name(), _grade(GRADE_LOWEST)
{
	std::cerr << "Bureaucrat default constructed" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	:_name(name), _grade(grade)
{
	_checkGrade();
	std::cerr   << "Bureaucrat constructed with name " << _name
				<< " and grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
	:_name(other._name), _grade(other._grade)
{
	std::cerr << "Bureaucrat copy constructed" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_grade = other._grade;
	}
	std::cerr << "Bureaucrat copy assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cerr << "Bureaucrat " << _name << " destructed" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const
{
	return (_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	_grade--;
	_checkGrade();
}

void	Bureaucrat::decrementGrade(void)
{
	_grade++;
	_checkGrade();
}

void	Bureaucrat::signForm(Form& to_sign) const
{
	if (to_sign.getSigned())
	{
		std::cout << _name << " couldn't sign form " << to_sign.getName()
				  << " because it is already signed" << std::endl;
		return ;
	}
	try
	{
		to_sign.beSigned(*this);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		std::cout << _name << " couldn't sign form " << to_sign.getName()
				  << " because their level is too low" << std::endl;
	}
	std::cout << _name << " signed form " << to_sign.getName() << std::endl;
}

void	Bureaucrat::_checkGrade(void)
{
	if (_grade < GRADE_HIGHEST)
		throw (GradeTooHighException());
	if (_grade > GRADE_LOWEST)
		throw (GradeTooLowException());
}

const char	*Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Bureaucrat::GradeTooHighException");
}

const char	*Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Bureaucrat::GradeTooLowException");
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}
