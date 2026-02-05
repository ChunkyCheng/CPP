#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class	Form
{
	public:
		Form(void);
		Form(const std::string& name, int grade_to_sign, int grade_to_execute);
		Form(const Form& other);
		Form&	operator=(const Form& other);
		~Form(void);

		const std::string&	getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;

		void	beSigned(const Bureaucrat& signer);

	protected:
	private:
		std::string	_name;
		bool		_signed;
		const int	_grade_to_sign;
		const int	_grade_to_execute;

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

std::ostream&	operator<<(std::ostream& os, const Form& obj);

#endif
