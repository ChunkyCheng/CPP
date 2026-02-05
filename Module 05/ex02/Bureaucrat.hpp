#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat&	operator=(const Bureaucrat& other);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		int					getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);
		void	signForm(AForm& form) const;
		void	executeForm(const AForm& form) const;
		
	protected:
	private:
		std::string	_name;
		int			_grade;

		void	_checkGrade(void);

		static const int	GRADE_HIGHEST;
		static const int	GRADE_LOWEST;
	
	public:
		class	GradeTooHighException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
		class	GradeTooLowException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& obj);

#endif
