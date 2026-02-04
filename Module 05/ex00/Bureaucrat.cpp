#include "Bureaucrat.hpp"

const int	Bureaucrat::GRADE_MIN = 1;
const int	Bureaucrat::GRADE_MAX = 150;

Bureaucrat::Bureaucrat(void)
	:_name(), _grade(GRADE_MAX)
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
}

void	Bureaucrat::decrementGrade(void)
{
	_grade++;
}

void	Bureaucrat::_checkGrade(void)
{
	if (_grade < GRADE_MIN)
		throw (GradeTooHighException());
	if (_grade > GRADE_MAX)
		throw (GradeTooLowException());
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return (os);
}
